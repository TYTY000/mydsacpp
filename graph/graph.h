#ifndef __GRAPH__
#define __GRAPH__

#include <climits>
#include "../stack/stack.h"
#include "../vector/vector.h"

using Rank = unsigned int;
typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te>
class Graph {
  private:
    void reset()
    {
      for (Rank v = 0; v < n; v++) {
        status( v ) = UNDISCOVERED;
        parent( v ) = -1;
        dTime ( v ) = fTime ( v ) = -1;
        priority( v ) = INT_MAX;
        for (Rank u = 0; u < n ; u++) {
          if ( exists( v, u ) ) {
            type( v, u ) = UNDETERMINED;
          }
        }
      }
    }

  void BFS( Rank, Rank& );
  void DFS( Rank, Rank& );
  void BCC( Rank, Rank&, Stack<Rank>& );
  bool TSort( Rank, Rank&, Stack<Tv>* );
  template <typename PU> void PFS( Rank, PU );

  public:
   //     vertex
    Rank n;
    virtual Rank insert( const Tv& ) = 0;
    virtual Tv remove ( Rank ) = 0;
    virtual Tv& vertex ( Rank ) = 0;
    virtual Rank inDegree ( Rank ) = 0;
    virtual Rank outDegree ( Rank ) = 0;
    virtual Rank firstNbr ( Rank ) = 0;
    virtual Rank nextNbr ( Rank, Rank ) = 0;
    virtual VStatus& status ( Rank ) = 0;
    virtual Rank& parent ( Rank ) = 0;
    virtual Rank& dTime ( Rank ) = 0;
    virtual Rank& fTime ( Rank ) = 0;
    virtual int& priority ( Rank ) = 0;
    //  edge 
    Rank e;
    virtual bool exists ( Rank, Rank ) = 0;
    virtual void insert ( const Te&, int, Rank, Rank ) = 0;
    virtual Te remove ( Rank , Rank ) = 0;
    virtual EType& type ( Rank, Rank ) = 0;
    virtual Te& edge ( Rank,  Rank ) = 0;
    virtual int& weight ( Rank, Rank ) = 0;
    // algorithm
    void bfs ( Rank );
    void dfs ( Rank );
    void bcc ( Rank );
    Stack< Tv > tSort ( Rank );
    void prim ( Rank );
    void dijkstra ( Rank );
    template <typename PU> void pfs ( Rank, PU );
};



#include "graph_bfs.h"
#include "graph_dfs.h"
// #include "graph_bfs_PU.h"
// #include "graph_dfs_PU.h"
// #include "graph_tsort.h"
// #include "graph_bcc.h"
// #include "graph_prim.h"
// #include "graph_dijkstra.h"
// #include "graph_pfs.h"
// #include "graph_prim_PU.h"
// #include "graph_dijkstra_PU.h"


#endif // !__GRAPH__
