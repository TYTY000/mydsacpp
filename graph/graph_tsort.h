/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 10:35:29
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 15:16:06
 */

#ifndef __GRAPH_TSORT__
#define __GRAPH_TSORT__

#include "../stack/stack.h"

template <typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::tSort(Rank r) 
{
  reset();
  Rank clock = 0;
  Stack<Tv> *S = new Stack<Tv>;
  for (Rank v = r; v < r + Graph<Tv, Te>::n; v++) {
    if (status(v % Graph<Tv, Te>::n) == UNDISCOVERED) {
      if (!TSort(v, clock, S))
        while (!S->empty())
          S->pop();
      break;
    }
  }
  return S;
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(Rank v, Rank &clock, Stack<Tv> *S) {
  dTime(v) = ++clock;
  status(v) = DISCOVERED;
  for (Rank i = firstNbr(v); i < Graph<Tv, Te>::n; i = nextNbr(v, i)) {
    switch (status(i)) {
    case UNDISCOVERED:
      parent(i) = v;
      if (!TSort(i, clock, S))
        return false;
      break;
    case DISCOVERED:
      return false;
    default /*VISITED*/:
      break;
    }
  }
  status(v) = VISITED;
  S->push(vertex(v));
  return true;
}

#endif // !__GRAPH_TSORT__
