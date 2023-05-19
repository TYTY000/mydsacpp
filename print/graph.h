
#include <boost/core/demangle.hpp>
template <typename Tv, typename Te>     // ¶¥µãÀàÐÍ¡¢±ßÀàÐÍ
void Print::p(GraphMatrix<Tv, Te> &s) { // ÒýÓÃ
  Rank inD = 0;
  for (Rank i = 0; i < s.n; i++)
    inD += s.inDegree(i);
  Rank outD = 0;
  for (Rank i = 0; i < s.n; i++)
    outD += s.outDegree(i);
  std::cout << boost::core::demangle(typeid(s).name()) << "\t "
            << "\tvertexes: " << s.n << "  edges: " << s.e
            << std::endl; // »ù±¾ÐÅÏ¢
  // ±êÌâÐÐ
  print(s.n);
  printf(" ");
  print(inD);
  printf("|");
  for (Rank i = 0; i < s.n; i++) {
    print(s.vertex(i));
    printf("[");
    print(s.status(i));
    printf("] ");
  }
  printf("\n");
  // ±êÌâÐÐ£¨Ðø£©
  print(outD);
  printf(" ");
  print(s.e);
  printf("|");
  for (Rank i = 0; i < s.n; i++) {
    print(s.inDegree(i));
    printf(" ");
  }
  printf("| dTime fTime Parent Weight\n");
  // Ë®Æ½·Ö¸ôÏß
  printf("-----------+");
  for (Rank i = 0; i < s.n; i++)
    printf("------");
  printf("+----------------------------\n");
  // ÖðÐÐÊä³ö¸÷¶¥µã
  for (Rank i = 0; i < s.n; i++) {
    print(s.vertex(i));
    printf("[");
    print(s.status(i));
    printf("] ");
    print(s.outDegree(i));
    printf("|");
    for (Rank j = 0; j < s.n; j++)
      if (s.exists(i, j)) {
        print(s.edge(i, j));
        print(s.type(i, j));
      } else
        printf("     .");
    printf("| ");
    print(s.dTime(i));
    printf(" ");
    print(s.fTime(i));
    printf("     ");
    if (-1 == s.parent(i))
      print("^");
    else
      print(s.vertex(s.parent(i)));
    printf("  ");
    if (INT_MAX > s.priority(i))
      print(s.priority(i));
    else
      print(" INF");
    printf("\n");
  }
  printf("\n");
}
