#include "../print/print.cpp"
#include "graph_matrix.h"
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

#define dice(x) (rand() % (x))

template <typename Tv, typename Te> // ¶¥µãÀàÐÍ¡¢±ßÀàÐÍ
void randomGraph(GraphMatrix<Tv, Te> &g, Rank n,
                 Rank e) {                // assert: 0 < e(e-1) <= v
  while ((g.n < n) || (g.e < e)) {        // Ëæ»ú²âÊÔ
    if (g.n < n) {                        // ¶¥µã
      if (dice(100) < 65) {               // 65%¸ÅÂÊ²åÈë¶¥µã
        Tv vertex = (Tv)('A' + dice(26)); /*DSA*/
        printf("Inserting vertex");
        print(vertex);
        printf(" ...");
        g.insert(vertex); /*DSA*/
        printf("done\n");
      } else { // 35%¸ÅÂÊÉ¾³ý¶¥µã
        if (1 > g.n)
          continue;
        int v = dice(g.n); /*DSA*/
        printf("Removing vertex %d ...", v);
        Tv x = g.remove(v); /*DSA*/
        printf("done with");
        print(x);
        printf("\n");
      }
      /*DSA*/ print(g);
    }
    if ((1 < g.n) && (g.e < e)) { // ±ß
      if (dice(100) < 65) {       // 65%¸ÅÂÊ²åÈë±ß
        int v = dice(g.n), j = dice(g.n);
        Te e = dice((Te)3 * n);
        /*DSA*/ printf("Inserting edge (%d, %d) = ", v, j);
        print(e);
        printf(" ...");
        if (g.exists(v, j)) {
          /*DSA*/ printf("already exists\n");
        } else {
          g.insert(e, e, v, j); /*DSA*/
          printf("done\n");
        }
      } else { // 35%¸ÅÂÊÉ¾³ý±ß
        int v = dice(g.n), j = dice(g.n);
        /*DSA*/ printf("Removing edge (%d, %d) ...", v, j);
        if (g.exists(v, j)) {
          Te e = g.remove(v, j); /*DSA*/
          printf("done with");
          print(e);
          printf("\n");
        } else {
          /*DSA*/ printf("not exists\n");
        }
      }
      /*DSA*/ print(g);
    }
  }
  for (Rank v = 0; v < n; v++)
    g.vertex(v) = 'A' + (Tv)v;
  /*DSA*/ print(g);
}

void importGraph(GraphMatrix<char, int> &g) {
  int n;
  scanf("%d\n", &n); /*DSA*/
  printf("%d vertices\n", n);
  for (int v = 0; v < n; v++) { // ²åÈëv¸ö¶¥µã
    char vertex;
    scanf("%c", &vertex); /*DSA*/
    printf("Inserting vertex");
    print(vertex);
    printf(" ...");
    g.insert(vertex); /*DSA*/
    printf("done\n");
    print(g);
  }
  for (int v = 0; v < n; v++)
    for (int j = 0; j < n; j++) { // ²åÈë±ß
      int edge;
      scanf("%d", &edge);
      if (0 > edge)
        continue; /*DSA*/
      printf("Inserting edge (%d, %d) = ", v, j);
      print(edge);
      printf(" ...");
      g.insert(edge, edge, v, j); /*DSA*/
      printf("done\n");
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &V) {
  int row = V.size();
  for (Rank i = 0; i < V.size(); i++) {
    if (V[i] != INT_MAX)
      os << V[i] << "\t";
    else
      os << "INT_MAX"
         << "\t";
    if ((i + 1) % row == 0)
      os << "\n";
  }
  return os;
}

void floyd(GraphMatrix<char, int> &g) {
  vector<vector<int>> dp(g.n, vector<int>(g.n));
  // init
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++) {
      if (i == j) {
        dp[i][j] = 0;
      } else if (g.exists(i, j)) {
        dp[i][j] = g.edge(i, j);
      } else {
        dp[i][j] = INT_MAX;
      }
    }
  }
  for (auto &row : dp) {
    cout << row;
  }
  cout << endl << endl;
  for (int k = 1; k < g.n; k++) {
    for (int i = 1; i < g.n; i++) {
      for (int j = 1; j < g.n; j++) {
        if ((dp[i][k] != INT_MAX) && (dp[k][j] != INT_MAX) &&
            (dp[i][j] > dp[i][k] + dp[k][j]))
          dp[i][j] = dp[i][k] + dp[k][j];
      }
    }
  }
  for (auto &row : dp) {
    cout << row;
  }
}
/******************************************************************************************
 * Í¼½á¹¹µÄÍ³Ò»²âÊÔ
 ******************************************************************************************/
int main(int argc, char *argv[]) {
  if (2 > argc) {
    printf("Usage: %s -random <n> <e> | -import <n> <e> < <path>\a\a\n",
           argv[0]);
    return -1;
  }
  // -import < ..\..\_input\graph.prim.0009+0028.txt
  // ..\..\_output\Graph_Matrix\graph.prim.0009+0028.txt -random 67 543 >
  // ..\..\_output\Graph_Matrix\graph.random.0067+0543.txt
  srand((unsigned int)time(NULL)); // Ëæ»úÖÖ×Ó
  // srand( 3141592653 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
  GraphMatrix<char, int> g;
  if (!strcmp("-random", argv[1]))
    randomGraph<char, int>(g, atoi(argv[2]),
                           atoi(argv[3])); // ¶¥µãÒÔ×Ö·û±àºÅ£¬±ßÎªÕûÊýÈ¨ÖØ
  else if (!strcmp("-import", argv[1]))
    importGraph(g); // ´ÓÃüÁîÐÐ£¨ÎÄ¼þÖØ¶¨Ïò£©ÖÐµ¼ÈëÍ¼
  else
    return -1;
  /*DSA*/ printf("\n");
  print(g);
  /*DSA*/ printf("=== Full BFS\n");
  std::cout
      << "Note : dTime -> trav level, fTime -> parent vertex traversal order."
      << std::endl;
  g.bfs(0); /*DSA*/
  print(g);
  /*DSA*/ printf("=== BFS (PFS)\n");
  g.pfs(0, BFSPU<char, int>()); /*DSA*/
  print(g);
  /*DSA*/ printf("=== Full DFS\n");
  g.dfs(0); /*DSA*/
  print(g);
  /*DSA*/ printf("=== DFS (PFS)\n");
  g.pfs(0, DFSPU<char, int>()); /*DSA*/
  print(g);
  /*DSA*/ printf("=== TopoSort\n");
  Stack<char> *ts = g.tSort(0); /*DSA*/
  std::cout << *ts << std::endl;
  print(g);
  delete ts;
  /*DSA*/ printf("=== BCC\n");
  g.bcc(0); /*DSA*/
  print(g);
  /*DSA*/ printf("=== Prim\n");
  g.prim(0); /*DSA*/
  print(g);
  /*DSA*/ printf("=== Prim (PFS)\n");
  g.pfs(0, PRIMPU<char, int>()); /*DSA*/
  print(g);
  /*DSA*/ printf("=== Dijkstra\n");
  g.dijkstra(0); /*DSA*/
  print(g);
  /*DSA*/ printf("=== Dijkstra (PFS)\n");
  g.pfs(0, DIJKPU<char, int>()); /*DSA*/
  print(g);
  floyd(g);
  cout << "Since path exists, you can backtrace to find the path." << endl;
  return 0;
}
