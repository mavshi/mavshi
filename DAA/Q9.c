//Q9. Write a program in C/C++/ Java to implement optimal binary search tree and also
//calculate the best case and worst case complexity.
//Sol
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int optimalBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    if (n == 0) return 0; 
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        cost[i][i] = freq[i];
    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i <= n - L; ++i) { 
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; ++r) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        ((r >= i && r <= j) ? freq[r] : 0);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}
int main() {
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    int minCost = optimalBST(keys, freq);
    cout << "Minimum cost of optimal BST: " << minCost << endl;
    return 0;
}