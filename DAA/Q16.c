//Q16 Write a Java Program in C/C++/ Java to implement Traveling Salesman Problem using nearest neighbor algorithm
//Sol
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<int>> graph;
public:
    Graph(int vertices) : V(vertices) {
        graph.resize(V, vector<int>(V, 0));
    }
    void addEdge(int src, int dest, int weight) {
        graph[src][dest] = weight;
        graph[dest][src] = weight;    }
    vector<int> nearestNeighborTSP() {
        vector<bool> visited(V, false);
        vector<int> path;
        int current = 0; 
        while (path.size() < V) {
            path.push_back(current);
            visited[current] = true;
            int nearestNeighbor = -1;
            int minDistance = INT_MAX;
            for (int neighbor = 0; neighbor < V; ++neighbor) {
                if (!visited[neighbor] && graph[current][neighbor] != 0 && graph[current][neighbor] < minDistance) {
                    minDistance = graph[current][neighbor];
                    nearestNeighbor = neighbor;
                }
            }
            if (nearestNeighbor == -1) {
                path.push_back(0);
                break;
            }
            current = nearestNeighbor;
        }
        return path;
    }
};

int main() {
    int V = 5; 
    Graph graph(V);
graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 20);
    graph.addEdge(0, 4, 25);
    graph.addEdge(1, 2, 35);
    graph.addEdge(1, 3, 45);
    graph.addEdge(1, 4, 55);
    graph.addEdge(2, 3, 65);
    graph.addEdge(2, 4, 75);
    graph.addEdge(3, 4, 85);
    vector<int> path = graph.nearestNeighborTSP();
    cout << "Path found using Nearest Neighbor Algorithm:" << endl;
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}
