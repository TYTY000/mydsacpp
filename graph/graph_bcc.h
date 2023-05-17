/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 14:23:09
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 15:14:40
 */

#ifndef __GRAPH_BCC__
#define __GRAPH_BCC__

#include "../stack/stack.h"

template <typename Tv, typename Te> void Graph<Tv, Te>::bcc(Rank r) {
  reset();
  Rank clock = 0;
  Rank v = r;
  Stack<Rank> S;
  for (Rank v = r; v < r + Graph<Tv, Te>::n; v++)
    if (status(v % Graph<Tv, Te>::n) == UNDISCOVERED)
      BCC(v % Graph<Tv, Te>::n, clock, S);
}

#define hca(x) (fTime(x))
template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(Rank v, Rank &clock, Stack<Rank> &S) {
  status(v) = DISCOVERED;
  hca(v) = dTime(v) = ++clock;
  S.push(v);
  for (Rank u = firstNbr(v); u < Graph<Tv, Te>::n; u = nextNbr(v, u)) {
    switch (status(u)) {
    case UNDISCOVERED:
      parent(u) = v;
      BCC(u, clock, S);
      if (hca(u) < dTime(v)) { //  u higher than v
        hca(v) = std::min(hca(v), hca(u));
      } else { // v higher than u
        while (v != S.pop())
          ; // clear v's child
        S.push(v);
      }
      break;
    case DISCOVERED:
      if (u != parent(v))
        hca(v) = std::min(hca(v), hca(u));
      break;
    default:
      break;
    }
  }
  status(v) = VISITED;
}
#undef hca
#endif // !__GRAPH_BCC__
