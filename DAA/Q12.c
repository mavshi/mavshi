//Q12 Write a Program in C/C++/Java to find only length of Longest Common Subsequence.

//Sol


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int longestCommonSubsequenceLength(string str1, string str2) 
{
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequenceLength(str1, str2) << endl;

    return 0;
}
