//Q6. Write a program in C/C++/ Java to find Minimum Cost Spanning Tree of a given
//undirected graph using Prim‟s algorithm
sol
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;
vector<int> primMST(const Graph& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> minWeight(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    minWeight[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && weight < minWeight[v]) {
                parent[v] = u;
                minWeight[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    return parent;
}
void printMST(const vector<int>& parent, const Graph& graph) {
    int n = graph.size();
    cout << "Minimum Spanning Tree:" << endl;
    int totalWeight = 0;
    for (int i = 1; i < n; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]].second << endl;
        totalWeight += graph[i][parent[i]].second;
    }
  cout << "Total weight of MST: " << totalWeight << endl;
}
int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    Graph graph(n);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;
    vector<int> parent = primMST(graph, start);
    printMST(parent, graph);
    return 0;
}
