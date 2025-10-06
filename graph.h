#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

#include "edge.h"
#include "vertex.h"
#include "heap.h"

using namespace std;


class Graph
{
  public:
    Graph();
    Graph(string filename);
    virtual ~Graph();
    int components(); // GTM Code Fragment 13.9, p. 617
    void dft( Vertex& ); // initialize() -> dfsTraversal
    int getDistance( const Vertex & ) const; // for Djikstra's algorithm
    Vertex& getVertexByName( const string &s );
    virtual void print();
    void read( istream &in = cin );
    void shortestPath( const Vertex& ); // Djikstra's algorithm
    vector<int> adjacentVertices( const Vertex & );
    
  protected:
    void dfsTraversal( Vertex & );  // GTM Code Fragment 13.7, p. 616
    //
    // Modifications of Code Fragments 13.4, 13.5, and 13.6
    //
    void initialize();              // resets vertex and edge labels
    virtual void startVisit( Vertex & ) {}
    virtual void traverseBack( Edge &e, Vertex& from ) { e.label = EdgeLabel::back; }
    virtual void traverseCross( Edge &e, Vertex& from ) { e.label = EdgeLabel::cross; }
    virtual void traverseDiscovery( Edge &e, Vertex& from ) { e.label = EdgeLabel::discovery; }
    virtual void finishVisit( Vertex & ) {}
    virtual bool isDone() const { return false; }
    void visit( Vertex &v ) { v.label = VertexLabel::visited; }
    void visit( Edge &e ) { e.label = EdgeLabel::visited; }
    void unvisit( Vertex &v ) { v.label = VertexLabel::unvisited; }
    void unvisit( Edge &e ) { e.label = EdgeLabel::unvisited; }
    bool isVisited( const Vertex &v ) const { return v.label == VertexLabel::visited; }
    bool isVisited( const Edge & e ) const { return e.label != EdgeLabel::unvisited; }

  private:
    /** vertices */
    vector<Vertex> Vertices;
    /** edges */
    vector<Edge> Edges;
    /** adjacency matrix */
    vector<vector<int>> Matrix;
    /** distances */
    vector<int> Distances; // for Djikstra's algorithm

}; // Graph class

#endif // GRAPH_H
