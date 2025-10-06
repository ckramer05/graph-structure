#include "main.h"

using namespace std;

int main() {
  try {
    Graph graph("/home/cck63/project5/france.dta");
    graph.print();
    graph.dft(graph.getVertexByName("nice"));
    
    cout << "Vertex nice by name: " << graph.getVertexByName("nice").name << endl;
    cout << endl << graph.components() << " components" << endl;
    
    cout << endl << endl << endl;

    PathFinder pathfinder("france.dta");
    cout << pathfinder.find(pathfinder.getVertexByName("paris"),pathfinder.getVertexByName("nice")) << endl;
    
    cout << endl << endl;

    cout << pathfinder.find(pathfinder.getVertexByName("marseille"),pathfinder.getVertexByName("paris")) << endl;

    cout << endl << endl;

    graph.shortestPath(graph.getVertexByName("paris"));

    cout << graph.getDistance(graph.getVertexByName("avignon")) << endl;
    
    cout << endl;

    cout << endl << "DONE" << endl;

    return 0;
  }
  catch (NoSuchObject &e) {
    cout << "\t NoSuchObject object caught in function main:" << endl;
    cout << e.what() << endl;
  }
  catch (invalid_argument &e) {
    cout << "\t invalid_argument object caught in function main: " << endl;
    cout << e.what() << endl;
  }
} 
