#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum class VertexLabel { visited, unvisited };

class Vertex
{
  friend ostream &operator<<( ostream &, const Vertex & );

  public:
    string name;
    VertexLabel label;
    int index;
    vector<int> incidentEdges;

    Vertex();
    Vertex( const string & );
    string labelToString() const;
    bool operator==( const Vertex & ) const;
    bool unvisited() const;
};

#endif // VERTEX_H
