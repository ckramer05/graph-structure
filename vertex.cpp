#include "vertex.h"

Vertex::Vertex() {
  name = "";
  label = VertexLabel::unvisited;
  index = 0;
}

Vertex::Vertex(const string &name) {
  this->name = name;
  label = VertexLabel::unvisited;
  index = 0;
}

string Vertex::labelToString() const {
  if (label == VertexLabel::unvisited) {
    return "unvisited";
  }
  else {
    return "visted";
  }
}

bool Vertex::operator==(const Vertex &v) const {
  if (name == v.name && index == v.index) {
    return true;
  }
  else {
    return false;
  }
}

bool Vertex::unvisited() const {
  return (label == VertexLabel::unvisited);
}

ostream& operator<<( ostream &os, const Vertex &v) {
  os << "(" << v.index << ", " << v.name << ", " << v.labelToString() << ")";
  
  return os;
}
