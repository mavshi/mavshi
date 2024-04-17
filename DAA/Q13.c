//Q13 Write programs in C/C++/ Java to implement DFS and BFS. Compare the time complexity
//Sol
 #include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void dfs(vector<vector<int>>& graph, int start) {
		int V = graph.size();
		vector<bool> visited(V, false);
		stack<int> stack;
		stack.push(start);
		visited[start] = true;
		while (!stack.empty()) {
		int current = stack.top();
		stack.pop();
		cout << current << " ";
	 for (int i = 0; i < graph[current].size(); ++i) {
	int neighbor = graph[current][i];
	if (!visited[neighbor]) {
	stack.push(neighbor);
	visited[neighbor] = true;
	}
	}
	}
}
void bfs(vector<vector<int>>& graph, int start) {
		int V = graph.size();
		vector<bool> visited(V, false);
		queue<int> queue
		queue.push(start);
		visited[start] = true;
		while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
	         cout << current << " ";
		for (int i = 0; i < graph[current].size(); ++i) {
		int neighbor = graph[current][i];
		if (!visited[neighbor]) {
		queue.push(neighbor);
	         visited[neighbor] = true;
		}		
                     }
	        }
                 }
int main() {
		vector<vector<int>> graph = {
				{1, 2},
				{0, 3, 4},
				{0, 5},
				{1},
				{1},
				{2}
		};

		cout << "DFS traversal: ";
		dfs(graph, 0);
		cout << endl;
		cout << "BFS traversal: ";
		bfs(graph, 0);
		cout << endl;
		return 0;
}
