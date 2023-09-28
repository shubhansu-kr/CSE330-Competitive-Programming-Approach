// 0-1 KnapSack : Complete or nothing

#include <bits/stdc++.h>
using namespace std ;

class Solution1{
    // Recursion: Memoization
public: 
    int solve(vector<vector<int>> &dp, vector<int> &values, vector<int> &weight, int bag, int i) {
        if (i < 0 || bag <= 0) return 0;

        if (dp[i][bag] != -1) return dp[i][bag];

        // pick
        int pick = INT_MIN;
        if (bag >= weight[i]) {
            pick = values[i] + solve(dp, values, weight, bag-weight[i], i-1);
        }
        // noPick
        int noPick = solve(dp, values, weight, bag, i-1);

        return dp[i][bag] = max(pick, noPick);
    }

    int knapSack(vector<int> &values, vector<int> &weight, int bag) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(bag+1, -1));

        return solve(dp, values, weight, bag, n-1);
    }
};

class Solution1{
    // Recursion: Optimised
public: 
    int solve(vector<int> &values, vector<int> &weight, int bag, int i) {
        if (i < 0 || bag <= 0) return 0;

        // pick
        int pick = INT_MIN;
        if (bag >= weight[i]) {
            pick = values[i] + solve(values, weight, bag-weight[i], i-1);
        }
        // noPick
        int noPick = solve(values, weight, bag, i-1);

        return max(pick, noPick);
    }

    int knapSack(vector<int> &values, vector<int> &weight, int bag) {
        int n = values.size();

        return solve(values, weight, bag, n-1);
    }
};

class Solution{
    // BruteForce: Recursion
public: 
    void solve(vector<int> &values, vector<int> &weight, int bag, int &ans, int steal, int i) {
        if (i < 0 || bag == 0) {
            ans = max(ans, steal);
            return;
        }

        // pick
        if (bag >= weight[i]) {
            solve(values, weight, bag-weight[i], ans, steal+values[i], i-1);
        }
        // noPick
        solve(values, weight, bag, ans, steal, i-1);
    }

    int knapSack(vector<int> &values, vector<int> &weight, int bag) {
        int n = values.size();

        int ans = INT_MIN, steal = 0;
        solve(values, weight, bag, ans, steal, n-1);
        return ans;
    }
};

int main () {
    
    return 0;
}