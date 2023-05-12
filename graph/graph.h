#ifndef __GRAPH__
#define __GRAPH__

#include "../stack/stack.h"

using Rank = unsigned int;
using VStatus = enum { UNDISCOVERED, DISCOVERED, VISITED };
using EType = enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD };

template <typename Tv, typename Tv>
class Graph {
  private:
    void reset()
    {
      for (Rank v = 0; v < n; v++) {
        status( v ) = UNDISCOVERED;
        parent( v ) = -1;
        dtime ( v ) = ftime ( v ) = -1;
        priority( v ) = INT_MAX;
        for (Rank u = 0; u < n ; u++) {
          if ( exists( v, u ) ) {
            type( v, u ) = UNDETERMINED;
          }
        }
      }
    }

   void BFS( Rank, Rank& ); //£¨Á¬Í¨Óò£©¹ã¶ÈÓÅÏÈËÑË÷Ëã
   void DFS( Rank, Rank& ); //£¨Á¬Í¨Óò£©Éî¶ÈÓÅÏÈËÑË÷Ëã
   void BCC( Rank, Rank&, Stack<Rank>& ); //£¨Á¬Í¨Óò£©»ùÓÚDFSµÄË«Á¬Í¨·ÖÁ¿·Ö½âËã
   bool TSort( Rank, Rank&, Stack<Tv>* ); //£¨Á¬Í¨Óò£©»ùÓÚDFSµÄÍØÆËÅÅÐòËã
   template <typename PU> void PFS( Rank, PU ); //£¨Á¬Í¨Óò£©ÓÅÏÈ¼¶ËÑË÷¿ò¼Ü

  public:
   //     vertex
    Rank n;
    virtual Rank insert( const Tv& ) = 0;
    virtual Tv remove ( Rank ) = 0;
    virtual Tv& vertex ( Rank ) = 0;
    virtual Rank inDegree ( Rank ) = 0;
    virtual Rank outDegree ( Rank ) = 0;
    virtual Rank firstNbr ( Rank ) = 0;
    virtual Rank nextNbr ( Rank ) = 0;
    virtual VStatus& status ( Rank ) = 0;
    virtual Rank& parent ( Rank ) = 0;
    virtual Rank& dtime ( Rank ) = 0;
    virtual Rank& ftime ( Rank ) = 0;
    virtual int& priority ( Rank ) = 0;
    //  edge 
    virtual exists ( Rank, Rank ) = 0;
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

#include "graph_imple.h"


#endif // !__GRAPH__
