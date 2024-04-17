//Q14 Write a program in C/C++/ Java for finding Topological sorting for Directed Acyclic Graph (DAG)
//Sol
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, stack<int>& result) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); ++i) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, result);
        }
    }
    result.push(node);
}
vector<int> topologicalSort(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    stack<int> result;
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(graph, i, visited, result);
        }
    }
    vector<int> sorted;
    while (!result.empty()) {
        sorted.push_back(result.top());
        result.pop();
    }
    return sorted;
}
int main() {
    int V = 6; 
    vector<vector<int>> graph(V);
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);
    vector<int> sorted = topologicalSort(graph, V);
    cout << "Topological sorting order: ";
    for (int i = 0; i < sorted.size(); ++i) {
        cout << sorted[i] << " ";
    }
    cout << endl;
    return 0;
