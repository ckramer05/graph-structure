#include "path.h"

Path::Path() {

}

void Path::push_back(const Vertex &v) {
  vertices.push_back(v);
}

void Path::pop_back() {
  vertices.pop_back();
}

void Path::clear() {
  vertices.clear();
}

size_t Path::size() const {
  return vertices.size();
}

ostream& operator<<( ostream &os, const Path &p ) {
  for (size_t i = 0; i < p.size(); i++) {
    if (i != 0) {
      os << " --> ";
    }
    os << "(" << p.vertices[i].index << ", " << p.vertices[i].name << ")";
  }
  return os;
}

