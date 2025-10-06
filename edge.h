#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <fstream>

#include "vertex.h"

using namespace std;


enum class EdgeLabel { visited, unvisited, discovery, back, cross };

class Edge
{
  public:
    string name;
    int w;
    int a; 
    int b; 

    EdgeLabel label;

    Edge();
    Edge( int a, int b, int w = 0 );
    string labelToString() const;
    int opposite( const Vertex &v ) const;
};

#endif // EDGE_H

