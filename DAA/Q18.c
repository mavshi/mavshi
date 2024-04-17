//Q18 Write a program in C/C++/ Java to implement Sum of Subset by Backtracking
//Sol
#include <iostream>
#include <vector>
using namespace std;
void sumOfSubset(vector<int>& weights, int targetSum, vector<int>& subset, int index, int currentSum) {
    if (currentSum == targetSum) {
        // Print the subset that sums up to the targetSum
        cout << "Subset found: ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    if (index == weights.size() || currentSum > targetSum) {
        return;
    }
    subset.push_back(weights[index]);
    sumOfSubset(weights, targetSum, subset, index + 1, currentSum + weights[index]);
    subset.pop_back();
 sumOfSubset(weights, targetSum, subset, index + 1, currentSum);
}
int main() {
    vector<int> weights = {10, 7, 5, 18, 12, 20, 15};
    int targetSum = 35;
    vector<int> subset;
    sumOfSubset(weights, targetSum, subset, 0, 0);
    return 0;
}
