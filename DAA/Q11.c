//Q11 Write a program in C/C++/ Java to find Minimum number of multiplications in Matrix Chain Multiplication

//Sol

#include <iostream>
#include <climits>
using namespace std;
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

        for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {

                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
           
          if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Matrix chain dimensions: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1)
            cout << "x";
    }
    cout << endl;

    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, n) << endl;

    return 0;
}
