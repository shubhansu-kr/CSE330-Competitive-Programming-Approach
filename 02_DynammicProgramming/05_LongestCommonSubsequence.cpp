// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std ;

class Solution2 {
    // Tabulation
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> dp(m+1, vector<int> (n+1));
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if (text1[i-1] == text2[j-1+]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};

class Solution1 {
    // Recursion: Memoization
public:
    int solve(vector<vector<int>> &dp, string &text1, string &text2, int i, int j){
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(dp, text1, text2, i-1, j-1);
        }

        return dp[i][j] = max(solve(dp, text1, text2, i-1, j), solve(dp, text1, text2, i, j-1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return dp[m-1][n-1] = solve(dp, text1, text2, m-1, n-1);
    }
};

class Solution {
    // Recursion
public:
    int solve(string &text1, string &text2, int i, int j){
        if (i < 0 || j < 0) return 0;
        if (text1[i] == text2[j]) {
            return 1 + solve(text1, text2, i-1, j-1);
        }
        return max(solve(text1, text2, i-1, j), solve(text1, text2, i, j-1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        return solve(text1, text2, m-1, n-1);
    }
};

int main () {
    
    return 0;
}