//Q15 Write a program in C/C++/ Java to determine if a given graph is a Hamiltonian cycle or not

//Sol

#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    int V = graph.size();
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
bool hamiltonianCycle(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> path(V, -1);
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1) == false)
        return false;
    return true;
}
int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    if (hamiltonianCycle(graph))
        cout << "The given graph contains a Hamiltonian cycle." << endl;
    else
        cout << "The given graph does not contain a Hamiltonian cycle." << endl;
    return 0;
}
