#ifndef FINDER_H
#define FINDER_H

#include <string>

#include "graph.h"
#include "path.h"
#include "vertex.h"

using namespace std;

class PathFinder : public Graph
{
  public:
    PathFinder();
    PathFinder( string );
    Path find( Vertex &, Vertex & );

  protected:
    virtual void startVisit( Vertex & );
    virtual void finishVisit( Vertex & );
    virtual bool isDone() const;

  private:
    Path path;
    Vertex target;
    bool done;
};

#endif // FINDER_H

