//Q23 Write a program in C/C++/ Java to find out live node, E node and dead node from a given graph
//Sol
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Graph {
private:
  int V;
  vector<unordered_set<int>> adjList;
public:
  Graph(int vertices) : V(vertices) { adjList.resize(V); }
  void addEdge(int u, int v) {
    adjList[u].insert(v);
    adjList[v].insert(u);
  }
  void findNodes() {
    unordered_set<int> liveNodes;
    unordered_set<int> deadNodes;
    for (int i = 0; i < V; ++i) {
      liveNodes.insert(i);
    }
    for (int i = 0; i < V; ++i) {
      if (!adjList[i].empty()) {
        liveNodes.insert(i);
        deadNodes.erase(i);
        for (int neighbor : adjList[i]) {
          liveNodes.insert(neighbor);
          deadNodes.erase(neighbor);
        }
      } else {
        liveNodes.erase(i);
        deadNodes.insert(i);
      }
    }
    int edges = 0;
    for (int i = 0; i < V; ++i) {
      edges += adjList[i].size();
    }
    edges /= 2;    
    cout << "Live Nodes: ";
    for (int node : liveNodes) {
      cout << node << " ";
    }
    cout << endl;
    cout << "E-nodes: " << edges << endl;
    cout << "Dead Nodes: ";
    for (int node : deadNodes) {
      cout << node << " ";
    }
    cout << endl;
  }
};
int main() {
  int V = 6; 
  Graph graph(V);
    graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 5);
  // Finding live nodes, E-nodes, and dead nodes
  graph.findNodes();
  return 0;
}
