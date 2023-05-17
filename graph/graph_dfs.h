/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-16 11:49:28
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 12:03:31
 */

#ifndef __GRAPH_DFS__
#define __GRAPH_DFS__

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(Rank r) //  starter
{
  reset();
  Rank clock = 0;
  Rank v = r;
  for (Rank i = r; i < r + Graph<Tv, Te>::n; i++)
    if (status(i % Graph<Tv, Te>::n) == UNDISCOVERED)
      DFS(i % Graph<Tv, Te>::n, clock);
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(Rank r, Rank &clock) {
  dTime(r) = ++clock;
  status(r) = DISCOVERED;
  for (Rank i = firstNbr(r); i < Graph<Tv, Te>::n; i = nextNbr(r, i))
    switch (status(i)) {
    case UNDISCOVERED:
      type(r, i) = TREE;
      parent(i) = r;
      DFS(i, clock);
      break;
    case DISCOVERED:
      type(r, i) = BACKWARD;
      break;
    default:
      type(r, i) = (dTime(i) > dTime(r)) ? FORWARD : CROSS;
      break;
    }
  status(r) = VISITED;
  fTime(r) = ++clock;
}

#endif // !__GRAPH_DFS__
