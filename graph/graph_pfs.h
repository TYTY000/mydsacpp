/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 15:16:22
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 16:01:04
 */

#ifndef __GRAPH_PFS__
#define __GRAPH_PFS__

#include <climits>
template <typename Tv, typename Te>
template <typename PU>  // PU needed!
void Graph<Tv, Te>::pfs(Rank r, PU prioUpdate) //  starter
{
  reset();
  for (Rank v = r; v < r + Graph<Tv, Te>::n; v++)
    if (status(v % Graph<Tv, Te>::n) == UNDISCOVERED)
      PFS(v % Graph<Tv, Te>::n, prioUpdate);
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(Rank v, PU prioUpdate) {
  priority(v) = 0;
  status(v) = VISITED;
  while (1) {
    for (Rank u = firstNbr(v); u < Graph<Tv, Te>::n; u = nextNbr(v, u)) {
      prioUpdate(this, v, u);
    }
    // now need to find new lowest priority
    int lowest = INT_MAX;
    for (Rank u = 0; u < Graph<Tv, Te>::n; u++) {
      if ((status(u) == UNDISCOVERED) && (priority(u) < lowest)) {
        v = u;
        lowest = priority(u);
      }
    }
    if (lowest == INT_MAX)
      break;
    status(v) = VISITED;
    //   v = u here
    type(parent(v), v) = TREE;
  }
}

#endif // !__GRAPH_PFS__
