/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-15 19:20:36
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-17 11:41:47
 */

#ifndef __GRAPH_MATRIX__
#define __GRAPH_MATRIX__

#define GraphMatrixVec 1

#include "./graph.h"
#include <algorithm>
#include <climits>
#include <tuple>

template <typename Tv> struct Vertex {
  Tv data;
  int inDegree, outDegree;
  VStatus status;
  Rank dTime, fTime;
  Rank parent;
  int priority;
  Vertex(const Tv &rhs = (Tv)0)
      : data(rhs), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1),
        fTime(-1), parent(-1), priority(INT_MAX) {}
};

template <typename Te> struct Edge {
  Te data;
  int weight;
  EType type;
  Edge(const Te &rhs, int w) : data(rhs), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te> class GraphMatrix : public Graph<Tv, Te> {
private:
  Vector<Vertex<Tv> > V;
  Vector<Vector<Edge<Te> *> > E; // trade space, flexibility for time
public:
  GraphMatrix() { Graph<Tv, Te>::n = Graph<Tv, Te>::e = 0; }
  ~GraphMatrix() {
    for (Rank j = 0; j < Graph<Tv, Te>::n; j++) {
      for (Rank k = 0; k < Graph<Tv, Te>::n; k++) {
        delete E[j][k];
      }
    }
  }

  virtual Tv &vertex(Rank i) { return V[i].data; }
  virtual Rank inDegree(Rank i) { return V[i].inDegree; }
  virtual Rank outDegree(Rank i) { return V[i].outDegree; }
  virtual Rank firstNbr(Rank i) { return nextNbr(i, 0); }
  virtual Rank nextNbr(Rank i, Rank j) {
    while ((j < Graph<Tv, Te>::n) && (!exists(i, ++j)));
    return j;
  }
  virtual VStatus &status(Rank i) { return V[i].status; }
  virtual Rank &parent(Rank i) { return V[i].parent; }
  virtual Rank &dTime(Rank i) { return V[i].dTime; }
  virtual Rank &fTime(Rank i) { return V[i].fTime; }
  virtual int &priority(Rank i) { return V[i].priority; }
  virtual Rank insert(const Tv &v) {
    for (Rank i = 0; i < GraphMatrix<Tv, Te>::n; i++)
      E[i].insert(NULL);
    Graph<Tv, Te>::n++;
    E.insert( Graph<Tv, Te>::n - 1, // need to specify rank!
        Vector<Edge<Te> *>(Graph<Tv, Te>::n, Graph<Tv, Te>::n,(Edge<Te>*)NULL));
    return V.insert(Vertex<Tv>(v));
  }
  virtual Tv remove(Rank i) {
    for (Rank j = 0; j < GraphMatrix<Tv, Te>::n; j++)
      if (exists(i, j)) {
        delete E[i][j];
        V[j].inDegree--;
        Graph<Tv, Te>::e--;
      }
    E.remove(i); Graph<Tv, Te>::n --;
    Tv vbak = vertex(i); V.remove(i);
    for (Rank j = 0; j < GraphMatrix<Tv, Te>::n; j++)
      if (Edge<Te> *x = E[j].remove(i)) {
        delete x;
        V[j].outDegree--;
        Graph<Tv, Te>::e--;
      }
    return vbak;
  }

  virtual bool exists(Rank i, Rank j) {
    return (i >= 0) && (i < Graph<Tv, Te>::n) && 
           (j >= 0) && (j < Graph<Tv, Te>::n) &&
           E[i][j] != NULL;
  }
  virtual EType &type(Rank i, Rank j) { return E[i][j]->type; }
  virtual Te &edge(Rank i, Rank j) { return E[i][j]->data; }
  virtual int &weight(Rank i, Rank j) { return E[i][j]->weight; }
  virtual void insert(const Te &edge, int weight, Rank i, Rank j) {
    if (exists(i, j))
      return;
    E[i][j] = new Edge<Te>(edge, weight);
    Graph<Tv, Te>::e++;
    V[i].outDegree++;
    V[j].inDegree++;
  }
  virtual Te remove(Rank i, Rank j) {
    Te ebak = edge(i, j);
    delete E[i][j];
    E[i][j] = NULL;
    Graph<Tv, Te>::e--;
    V[i].outDegree--;
    V[j].inDegree--;
    return ebak;
  }
};

#endif // !__GRAPH_MATRIX__
