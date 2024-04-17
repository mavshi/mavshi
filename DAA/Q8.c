//Q8 Write a program in C/C++/ Java to implement Knapsack problems using Greedy
//Method
//Sol
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int value;
    int weight;
    double ratio; 
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; }
double knapsackGreedy(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare); 
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (const auto& item : items) {
        if (remainingCapacity >= item.weight) { 
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else { 
            totalValue += (double)item.value * remainingCapacity / item.weight;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n; 
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter value and weight of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight; ratio
    }
    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    double maxValue = knapsackGreedy(capacity, items);
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    return 0;
}
