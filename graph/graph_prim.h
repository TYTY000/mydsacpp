/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 16:55:01
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 17:45:51
 */

#ifndef __GRAPH_PRIM__
#define __GRAPH_PRIM__

template <typename Tv, typename Te> void Graph<Tv, Te>::prim(Rank v) {
  reset();
  priority(v) = 0;
  // trav vertex
  for (Rank i = 0; i < Graph<Tv, Te>::n; i++) {
    status(v) = VISITED;
    if (parent(v) != -1)
      type(parent(v), v) = TREE;
    // greedy get lowest weight
    for (Rank u = firstNbr(v); u < Graph<Tv, Te>::n; u=nextNbr(v, u)) {
      if (status(u) == UNDISCOVERED) 
        if (priority(u) > weight(v, u)) {// greedy
        priority(u) = weight(v, u);
        parent(u) = v;
      }
    }
    int lowest = INT_MAX;
    // set v for next iter
    for (Rank j = 0; j < Graph<Tv, Te>::n; j++) {
      if ((status(j) == UNDISCOVERED) && (priority(j) < lowest)) {
        lowest = priority(j);
        v = j;
      }
    }
  }
}
#endif // !__GRAPH_PRIM__
