//Q17 Write a program in C/C++/ Java a to implement Graph Coloring Algorithm
//Sol
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<int>> adjList;
public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    void greedyColoring() {
        vector<int> result(V, -1);
        vector<bool> available(V, true);
        result[0] = 0; 
        for (int u = 1; u < V; u++) {
                        for (int neighbor : adjList[u]) {
                if (result[neighbor] != -1) {
                    available[result[neighbor]] = false;
                }
            }
            int color;
            for (color = 0; color < V; color++) {
                if (available[color])
                    break;
            }
            result[u] = color; 
            fill(available.begin(), available.end(), true);
        }
        // Print the coloring result
        cout << "Vertex   Color" << endl;
        for (int i = 0; i < V; i++) {
            cout << "  " << i << "\t     " << result[i] << endl;
        }
    }
};
int main() {
    int V = 5; 
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    // Perform graph coloring
    graph.greedyColoring();
    return 0;
}
