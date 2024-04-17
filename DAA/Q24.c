 //Q24 Write a program in C/C++/ Java to find out solution for travelling salesman problem using LCBB from a given matrix.

//Sol

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
    int level;
    int cost;
    vector<int> path;
    vector<bool> visited;
};

struct CompareNode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.cost > n2.cost;
    }
};
int calculateLB(const vector<vector<int>>& graph, const Node& node) {
    int lb = 0;
    for (int i = 0; i < node.level; ++i) {
        lb += graph[node.path[i]][node.path[i + 1]];
    }

    for (int i = 0; i < graph.size(); ++i) {
        if (!node.visited[i]) {
            int minEdge = INF;
            for (int j = 0; j < graph.size(); ++j) {
                if (i != j && !node.visited[j]) {
                    minEdge = min(minEdge, graph[i][j]);
                }
            }
            lb += minEdge;
        }
    }

    return lb;
}

void TSPBranchBound(const vector<vector<int>>& graph) {
    int n = graph.size();
    priority_queue<Node, vector<Node>, CompareNode> pq;

    Node root;
    root.level = 0;
    root.cost = 0;
    root.path.push_back(0);
    root.visited.assign(n, false);
    root.visited[0] = true;

    int minLength = INF;
    vector<int> minPath;

    pq.push(root);

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();
        if (currentNode.cost >= minLength) {
            continue;
        }
path
        if (currentNode.level == n - 1) {
            currentNode.path.push_back(0); // Return to the starting node
            if (currentNode.cost < minLength) {
                minLength = currentNode.cost;
                minPath = currentNode.path;
            }
            continue;
        }

        
        for (int i = 0; i < n; ++i) {
            if (!currentNode.visited[i]) {
                Node childNode = currentNode;
                childNode.path.push_back(i);
                childNode.visited[i] = true;
                childNode.cost += graph[currentNode.path[currentNode.level]][i];
                childNode.level++;
                childNode.cost += calculateLB(graph, childNode); // Calculate lower bound for the child node

                pq.push(childNode);
            }
        }
    }
    cout << "Minimum length: " << minLength << endl;
    cout << "Path: ";
    for (int node : minPath) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSPBranchBound(graph);

    return 0;
}
