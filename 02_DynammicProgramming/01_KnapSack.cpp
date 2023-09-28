// 0-1 KnapSack : Complete or nothing

#include <bits/stdc++.h>
using namespace std ;

class Solution5{
    // GFG: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W+1);

        for(int j = 0; j <= W; ++j) {
            if (j >= wt[0]) {
                prev[j] = val[0];
            }
        }

        for(int i = 1; i < n; ++i) {
            vector<int> temp(W+1);
            for(int j = 1; j <= W; ++j) {

                int pick = INT_MIN;
                if (j - wt[i] >= 0) {
                    pick = val[i] + prev[j-wt[i]];
                }
                int noPick = prev[j];

                temp[j] = max(pick, noPick);
            }
            prev = temp;
        }

        return prev[W];
    }
};

class Solution4{
    // Tabulation: Space Optimisation
public: 
    int knapSack(vector<int> &values, vector<int> &weight, int bag) {
        int n = values.size();

        vector<int> prev(bag+1);

        for(int j = 0; j <= bag; ++j) {
            if (j >= weight[0]) {
                prev[j] = values[0];
            }
        }

        for(int i = 1; i < n; ++i) {
            vector<int> temp(bag+1);
            for(int j = 1; j <= bag; ++j) {

                int pick = INT_MIN;
                if (j - weight[i] >= 0) {
                    pick = values[i] + prev[j-weight[i]];
                }
                int noPick = prev[j];

                temp[j] = max(pick, noPick);
            }
            prev = temp;
        }

        return prev[bag];
    }
};

class Solution3{
    // Tabulation:
public: 
    int knapSack(vector<int> &values, vector<int> &weight, int bag) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(bag+1));

        for(int j = 0; j <= bag; ++j) {
            if (j >= weight[0]) {
                dp[0][j] = values[0];
            }
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= bag; ++j) {

                int pick = INT_MIN;
                if (j - weight[i] >= 0) {
                    pick = values[i] + dp[i-1][j-weight[i]];
                }
                int noPick = dp[i-1][j];

                dp[i][j] = max(pick, noPick);
            }
        }

        return dp[n-1][bag];
    }
};

class Solution2{
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