/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-15 19:20:36
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-16 12:50:13
 */

#ifndef __GRAPH_MATRIX_LIST__
#define __GRAPH_MATRIX_LIST__

#define GraphMatrixList 1

#include "./graph.h"
#include <algorithm>
#include <climits>
#include <tuple>

template <typename Tv> struct Vertex{
  Tv data; int inDegree, outDegree; VStatus status;
  Rank dTime, fTime;
  Rank parent; int priority; 
  Vertex ( const Tv& rhs = (Tv) 0 ) :
                data(rhs), inDegree(0), outDegree(0), status(UNDISCOVERED),
                dTime(-1), fTime(-1), parent(-1), priority(INT_MAX)       {}
};

template <typename Te> struct Edge {
  Te data; int weight; EType type;
  Rank v;
  Edge ( const Te& rhs, int w, Rank r ) :
                data(rhs), weight(w), type(UNDETERMINED), v(r)   {}
};

template<typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
  {
  private:
    Vector< Vertex<Tv>() > V;
    Vector< List<Edge<Te>* > > E; // trade space, flexibility for time
  public:
    GraphMatrix() { Graph<Tv, Te>::n = Graph<Tv, Te>::e = 0; }
    ~GraphMatrix() 
    {
      for ( Rank j = 0; j < Graph<Tv, Te>::n; j++ ){
        for (auto p = E[j].first(); p != E[j].last(); p = p->next) {
          delete p->data;
        }
      }
    }
    
    Edge<Te>* getEdge ( Rank i, Rank j ) { auto e = E[i].first(); while ( e->v < j ) e = e->next; return (e->v == j) ? e : nullptr;}
    virtual Tv& vertex ( Rank i )            { return V[i].data; }
    virtual Rank inDegree ( Rank i )         { return V[i].inDegree; }
    virtual Rank outDegree ( Rank i )        { return V[i].outDegree; }
    virtual Rank firstNbr ( Rank i )         { return E[i].first()->v; }
    virtual Rank nextNbr ( Rank i, Rank j )  { auto f = E[i].first(); while( f->v < j ) f = f->next; return f->v; }
    virtual VStatus& status ( Rank i )       { return V[i].status;}
    virtual Rank& parent ( Rank i )          { return V[i].parent;}
    virtual Rank& dTime ( Rank i )           { return V[i].dTime;}
    virtual Rank& fTime ( Rank i )           { return V[i].fTime;}
    virtual int& priority ( Rank i )         { return V[i].priority;}
    virtual Rank insert( const Tv& v )       
    {
      for( Rank i = 0; i < GraphMatrix<Tv, Te>::n; i++) E[i].insertAsLast(NULL);
      Graph<Tv, Te>::n++;
      E.insert( List< Edge<Te>* >() );
      return V.insert( Vertex<Tv> ( v ) );
    }
    virtual Tv remove ( Rank i )
    {
      auto e = E[i].first();
      while( e->data ) { V[e->v].inDegree --; delete e; }
      E.remove(i); Graph<Tv, Te>::n--;
      Tv vbak = vertex(i); V.remove(i);
      Edge<Te>* p;
      for (Rank j = 0; j < Graph<Tv, Te>::n; j++) {
        if ( (p = getEdge(i, j)) != nullptr ) {
          E[j].remove(p); delete p; V[j].outDegree--;
        }
      }
      return vbak;
    }
    
    virtual bool exists ( Rank i, Rank j )   
    {
      if ( ! ( ( i >= 0 ) && ( i < Graph<Tv, Te>::n ) && ( j >= 0 ) && ( j < Graph<Tv, Te>::n ) ) ) return false;
      return ( getEdge( i, j )->v == j ) ? true : false; 
    } 
    virtual EType& type ( Rank i, Rank j ) { auto e = getEdge(i, j); return ( e == nullptr ) ? -1 : e->type; }
    virtual Te& edge ( Rank i, Rank j ) { auto e = getEdge(i, j); return ( e == nullptr ) ? -1 : e->data; }
    virtual int& weight ( Rank i, Rank j ) { auto e = getEdge(i, j); return ( e == nullptr ) ? -1 : e->weight; }
    virtual void insert ( const Te& edge, int weight, Rank i, Rank j )
    {
      if( exists(i, j) ) return;
      auto f = E[i].first(); while( f->v < j ) f = f->next;
      E[i].insert( Edge<Te> ( edge, weight, j ), f);
      Graph<Tv, Te>::e++; V[i].outDegree++; V[j].inDegree++;
    }
    virtual Te remove ( Rank i , Rank j ){
      Te ebak = edge(i, j);
      auto ptr = getEdge(i, j);
      if ( ptr != nullptr ) E[i].remove(ptr);
      Graph<Tv, Te>::e--; V[i].outDegree--; V[j].inDegree--;
    }
  };

#endif // !__GRAPH_MATRIX_LIST__
