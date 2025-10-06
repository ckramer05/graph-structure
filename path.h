#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <vector>
#include <fstream>

#include "vertex.h"

using namespace std;

class Path {

  friend ostream &operator<<( ostream &out, const Path &p );

  public:
    Path();
    void push_back( const Vertex & );
    void pop_back();
    void clear();
    size_t size() const;

  private:
    vector<Vertex> vertices;

}; // Path class

#endif // PATH_H
