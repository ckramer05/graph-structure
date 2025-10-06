#include "graph.h"

Graph::Graph() {

}

Graph::Graph(string filename) {
  ifstream file;
  file.open(filename.c_str());
  
  read(file);
}

Graph::~Graph() {

}

void Graph::initialize() {
  for (size_t i = 0; i < Vertices.size(); i++) {
    Vertices[i].label = VertexLabel::unvisited;
  }
  for (size_t i = 0; i < Edges.size(); i++) {
    Edges[i].label = EdgeLabel::unvisited;
  }
}

void Graph::dft(Vertex &v) {
  initialize();
  dfsTraversal(v);
}

void Graph::dfsTraversal(Vertex &v) {
  startVisit(v);
  v.label = VertexLabel::visited;
  for (int e: v.incidentEdges) {
    if (isDone()) {
      break;
    }
    if (Edges[e].label == EdgeLabel::unvisited) {
      int w = Edges[e].opposite(v);
      if (Vertices[w].label == VertexLabel::unvisited) {
        Edges[e].label = EdgeLabel::discovery;
        dfsTraversal(Vertices[w]);
      }
      else {
        Edges[e].label = EdgeLabel::back;
      }
    }
  }
  if (!isDone()) {
    finishVisit(v);
  }
}

int Graph::components() {
  initialize();
  int components = 0;
  for (size_t v = 0; v < Vertices.size(); v++) {
    if (Vertices[v].label == VertexLabel::unvisited) {
      dfsTraversal(Vertices[v]);
      components++;
    }
  }
  return components;
}

vector<int> Graph::adjacentVertices(const Vertex &v) {
  vector<int> adjacentVertices;
  for (int i: v.incidentEdges) {
    adjacentVertices.push_back(Edges[i].opposite(v));
  }

  return adjacentVertices;
}

int Graph::getDistance(const Vertex &v) const {
  return Distances[v.index];
}

void Graph::shortestPath(const Vertex &v) {
  for (size_t i = 0; i < Vertices.size(); i++) {
    if (v.index == static_cast<int>(i)) {
      Distances.push_back(0);
    }
    else {
      Distances.push_back(numeric_limits<int>::max());
    } 
  }

  Heap<int,string> Q;
  vector<Locator<int,string>> locators;
  
  for (size_t i = 0; i < Vertices.size(); i++) {
    locators.push_back(Q.insert(Distances[i],Vertices[i].name));
  }

  int u;
  Locator<int,string> locator;

  while (!Q.empty()) {
    u = getVertexByName(Q.remove()).index;
    locators[u].release();

    for (int z: adjacentVertices(Vertices[u])) {
      if (locators[z].isPresent()) {
        if ((Distances[u] + Edges[Matrix[u][z]].w) < Distances[z]) {
          Distances[z] = Distances[u] + Edges[Matrix[u][z]].w;
      
          Q.changeKey(Distances[z], locators[z]);
        }
      }
    }
  }
}

Vertex& Graph::getVertexByName(const string &s) {
  for (size_t i = 0; i < Vertices.size(); i++) {
    if (Vertices[i].name == s) {
      return Vertices[i];
    }
  }
  throw invalid_argument("ERROR: in method Graph::getVertexByName()");
}

void Graph::read(istream &is) {
  if (!is) {
    throw invalid_argument("ERROR: in method Graph::read()");
  }

  string direction;
  int vertices;

  is >> direction;

  is >> vertices;

  string name;
  int weight;

  vector<string> names(vertices, "");
  vector<vector<int>> inputMatrix(vertices, vector<int>(vertices,0));

  for (int i = 0; i < vertices; i++) {
    is >> name;
    names[i] = name;
  }

  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      is >> weight;
      inputMatrix[i][j] = weight;
    }
  }

  int count = 0;
  Vertex vertex;
  Edge edge;

  for (int i = 0; i < vertices; i++) {
    Matrix.push_back(vector<int>(vertices, -1));

    vertex = Vertex(names[i]);

    vertex.index = i;

    Vertices.push_back(vertex);

    for (int j = 0; j < vertices; j++) {
      if (inputMatrix[i][j] != 0) {
        if (direction == "U") {
          if (i < j) {
            edge = Edge(i,j,inputMatrix[i][j]);
            edge.name = direction;
            Edges.push_back(edge);
            
            Matrix[i][j] = count;
              
            Vertices[i].incidentEdges.push_back(Matrix[i][j]);

            count++;
          }
          else {
            Matrix[i][j] = Matrix[j][i];

            Vertices[i].incidentEdges.push_back(Matrix[i][j]);
          }
        }
        else if (direction == "D") {
          edge = Edge(i,j,inputMatrix[i][j]);
          edge.name = direction;
          Edges.push_back(edge);

          Matrix[i][j] = count;
          
          Vertices[i].incidentEdges.push_back(Matrix[i][j]);

          count++;
        }
      }
    }
  }
}

void Graph::print() {
  for (size_t i = 0; i < Matrix.size(); i++) {
    for (size_t j = 0; j < Matrix[i].size(); j++) {
      if (Matrix[i][j] != -1) {
        cout << setw(Vertices[j].name.length()) << Edges[Matrix[i][j]].w;
      }
      else {
        cout << setw(Vertices[j].name.length()) << "0";
      }
    }
    cout << "\t\t";
    for (size_t j = 0; j < Matrix[i].size(); j++) {
      cout << setw(Vertices[j].name.length()) << Matrix[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
