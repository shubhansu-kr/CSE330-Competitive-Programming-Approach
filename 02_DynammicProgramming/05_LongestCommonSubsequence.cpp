// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
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