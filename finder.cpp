#include "finder.h"

PathFinder::PathFinder() : Graph() {

}

PathFinder::PathFinder(string filename) : Graph(filename) {

}

Path PathFinder::find(Vertex &s, Vertex &t) {
  initialize();
  path.clear();
  target = t;
  done = false;
  dfsTraversal(s);
  return path;
}

void PathFinder::startVisit(Vertex &v) {
  path.push_back(v);
  if (v == target) {
    done = true;
  }
}

void PathFinder::finishVisit(Vertex &v) {
  if (!done) {
    path.pop_back();
  }
}

bool PathFinder::isDone() const {
  return done;
}

