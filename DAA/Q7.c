//Q7. Write a program in C/C++/ Java to from a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijikstra‟s algorithm
//Sol
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
typedef pair<int, int> pii; // pair<vertex, weight>
typedef vector<vector<pii>> Graph; // adjacency list representation
vector<int> dijkstra(const Graph& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF); // distance from source
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap (vertex, distance)
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) // If distance to u is already smaller, skip
            continue;
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    Graph graph(n);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> shortest_paths = dijkstra(graph, source);
    cout << "Shortest paths from vertex " << source << " to other vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        if (i != source) {
            if (shortest_paths[i] == INF)
                cout << "Vertex " << i << ": No path" << endl;
            else
                cout << "Vertex " << i << ": " << shortest_paths[i] << endl;
        }
    }
    return 0;
}


