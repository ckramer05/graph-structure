#include "edge.h"

Edge::Edge() {
  name = "";
  a = 0;
  b = 0;
  w = 0;
  label = EdgeLabel::unvisited;
}

Edge::Edge(int a, int b, int w) {
  name = "";
  this->a = a;
  this->b = b;
  this->w = w;
}

string Edge::labelToString() const {
  switch (label) {
    case EdgeLabel::visited:
      return "visited";
    case EdgeLabel::unvisited:
      return "unvisited";
    case EdgeLabel::discovery:
      return "discovery";
    case EdgeLabel::back:
      return "back"; 
    case EdgeLabel::cross:
      return "cross";
  }
  return "visited";
}

int Edge::opposite(const Vertex &v) const {
  if (v.index == a) {
    return b;
  }
  else if (v.index == b) {
    return a;
  }
  else {
    return 0;
  }
}
