//Q5..Write a program in C/C++/ Java to find Minimum Cost Spanning Tree of a given
//undirected graph using Kruskal‟s algorithm
//sol
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
int find(vector<Subset> &subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(vector<Subset> &subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskalMST(vector<Edge> &edges, int V) {
    vector<Edge> result(V - 1);
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Subset> subsets(V);
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int e = 0;
    int i = 0;
    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (i = 0; i < V - 1; ++i) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter source, destination and weight for each edge:" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    kruskalMST(edges, V);
    return 0;
}
