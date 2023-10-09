// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution3{
    // Tabulation
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N][W+1];

        // Zero bag weight: No pick possible.
        for(int i = 0; i < N; ++i) {
            dp[i][0] = 0;
        }

        // only one item
        for(int j = 1; j < W+1; ++j) {
            dp[0][j] = j/wt[0] * val[0];
        }

        for(int i = 1; i < N; ++i) {
            for(int j = 1; j < W+1; ++j) {
                int pick = 1e5, noPick;
                
                if (j >= wt[i]) {
                    pick = val[i] + dp[i][j-wt[i]];
                }

                noPick = dp[i-1][j];
                
                dp[i][j]  = max(pick, noPick);
            }
        }

        return dp[N-1][W];
    }
};

class Solution2{
    // Recursion: Memoization
public:
    int solve(int &dp[][], int val[], int wt[], int W, int i) {
        if (i < 0 || W <= 0) {
            return 0;
        }

        if (dp[i][W] != -1) return dp[i][W];

        int pick = 1e5, noPick;
        if (W >= wt[i]) {
            pick = val[i] + solve(dp, val, wt, W-wt[i], i);
        }

        noPick = solve(dp, val, wt, W, i-1);

        return dp[i][W] = max(pick, noPick);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N][W+1];
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < W+1; ++j) {
                dp[i][j] = -1;
            }
        }

        return solve(dp, val, wt, W, N-1);
    }
};

class Solution1{
    // Recursion: Optimised
public:
    int solve(int val[], int wt[], int W, int i) {
        if (i < 0 || W <= 0) {
            return 0;
        }

        int pick = 1e5, noPick;
        if (W >= wt[i]) {
            pick = val[i] + solve(val, wt, W-wt[i], i);
        }

        noPick = solve(val, wt, W, i-1);

        return max(pick, noPick);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(val, wt, W, N-1);
    }
};

class Solution{
    // BruteForce: Recursion
public:
    void solve(int val[], int wt[], int &ans, int &sum, int W, int i) {
        if (i < 0 || W <= 0) {
            ans = max(ans, sum);
            return;
        }

        if (W >= wt[i]) {
            sum += val[i];
            solve(val, wt, ans, sum, W-wt[i], i);
            sum -= val[i];
        }

        solve(val, wt, ans, sum, W, i-1);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        int ans = INT_MIN, sum = 0;
        solve(val, wt, ans, sum, W, N-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends