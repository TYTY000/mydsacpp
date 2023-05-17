/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-16 09:34:06
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 08:44:28
 */

#ifndef __GRAPH_BFS__
#define __GRAPH_BFS__

#include "../queue/queue.h"
template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(Rank r) //  starter
{
  reset();
  Rank clock = 0;
  for (Rank i = r; i < r + Graph<Tv, Te>::n; i++)
    if (status(i % Graph<Tv, Te>::n) == UNDISCOVERED)
      BFS(i % Graph<Tv, Te>::n, clock);
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(Rank r, Rank &clock) {
  Queue<Rank> Q;
  status(r) = DISCOVERED;
  dTime(r) = clock++;
  Q.enqueue(r);
  for (Rank fclock = 0; !Q.empty();) {
    if (dTime(r) < dTime(Q.peek())) {
      clock++;
      fclock = 0;
    }
    r = Q.dequeue();
    for (Rank i = firstNbr(r); i < Graph<Tv, Te>::n; i = nextNbr(r, i)) {
      if (status(i) == UNDISCOVERED) {
        status(i) = DISCOVERED;
        Q.enqueue(i);
        dTime(i) = clock;
        type(r, i) = TREE;
        parent(i) = r;
      } else {
        type(r, i) = CROSS;
      }
    }
    status(r) = VISITED;
    fTime(r) = fclock++;
  }
}

#endif // !__GRAPH_BFS__
