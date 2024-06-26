//Q22 Write a program in C/C++/ Java to find out longest common subsequence from the given strings

//Sol

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
   j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}
int main() {
    string str1 = "ABCBDAB";
    string str2 = "BDCAB";
 string lcs = longestCommonSubsequence(str1, str2);
cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}
