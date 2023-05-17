/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-17 15:38:32
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 17:55:28
 */

#ifndef __GRAPH_PU__
#define __GRAPH_PU__

// u is the nbr of v

template <typename Tv, typename Te> struct BFSPU {
  virtual void operator()(Graph<Tv, Te> *g, Rank v, Rank u) {
    if (g->status(u) == UNDISCOVERED)
      if (g->priority(u) > g->priority(v) + 1) {
        g->priority(u) = g->priority(v) + 1;
        g->parent(u) = v;
      }
  }
};

template <typename Tv, typename Te> struct DFSPU {
  virtual void operator()(Graph<Tv, Te> *g, Rank v, Rank u) {
    if (g->status(u) == UNDISCOVERED)
      if (g->priority(u) > g->priority(v) - 1) {           // on the contrary, -1.
        g->priority(u) = g->priority(v) - 1;
        g->parent(u) = v;
      }
  }
};

template <typename Tv, typename Te> struct PRIMPU {
  virtual void operator()(Graph<Tv, Te> *g, Rank v, Rank u) {
    if (g->status(u) == UNDISCOVERED)
      if (g->priority(u) > g->weight(v,u)) {
        g->priority(u) = g->weight(v,u);
        g->parent(u) = v;
      }
  }
};

template <typename Tv, typename Te> struct DIJKPU {
  virtual void operator()(Graph<Tv, Te> *g, Rank v, Rank u) {
    if (g->status(u) == UNDISCOVERED)
      if (g->priority(u) > g->weight(v,u) + g->priority(v)) {
        g->priority(u) = g->weight(v,u)+g->priority(v);
        g->parent(u) = v;
      }
  }
};
#endif // !__GRAPH_PU__
