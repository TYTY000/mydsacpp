/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 17:57:04
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 18:05:41
 */

#ifndef __GRAPH_DIJK__
#define __GRAPH_DIJK__

#include "graph.h"
template <typename Tv, typename Te> void Graph<Tv, Te>::dijkstra(Rank v) {
  reset();
  priority(v) = 0;
  for (Rank i = 0; i < Graph<Tv, Te>::n; i++) {
    status(v) = VISITED;
    if (parent(i) != -1) {
      type(parent(i), i) = TREE;
    }
    for (Rank u = firstNbr(v); u < Graph<Tv, Te>::n; u = nextNbr(v, u)) {
      if (status(u) == UNDISCOVERED)
        if (priority(u) > priority(v) + weight(v, u)) {
          priority(u) = priority(v) + weight(v, u);
          parent(u) = v;
        }
    }
    int lowest = INT_MAX;
    for (Rank i = 0; i < Graph<Tv, Te>::n; i++) {
      if (status(i) == UNDISCOVERED) {
        if (priority(i) < lowest) {
          lowest = priority(i);
          v = i;
        }
      }
    }
  }
}

#endif // !__GRAPH_DIJK__
