// Fibonacci Series: f(n) = f(n-1) + f(n-2): f(0) = 0, f(1) = 1
// Overlapping Subproblem

#include <bits/stdc++.h>
using namespace std ;

class Solution3 {
    // Tabulation: Space Optimised.
    // DP can be applied only when there is an overlapping subproblem.
public: 
    int fibo(int n) {
        if (n < 2) return n;

        int prev = 0, prev1 = 1;
 
        for(int i = 2; i < n+1; ++i) {
            int temp = prev1;
            prev1 = prev + prev1;
            prev = temp;
        }

        return prev1;
    }
}

class Solution2 {
    // Tabulation
    // DP can be applied only when there is an overlapping subproblem.
public: 
    
    int fibo(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1, -1);

        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i < n+1; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
}

class Solution1 {
    // Recursion: Memoization
    // DP can be applied only when there is an overlapping subproblem.
public: 
    int solve(vector<int> &dp, int i) {
        if (i < 2) return n;

        if (dp[i] != -1) return dp[i];

        return dp[i] = solve(dp, i-1) + solve(dp, i-2);
    }

    int fibo(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1, -1);

        return solve(dp, n-1) + solve(dp, n-2);
    }
}

class Solution {
    // BruteForce: Recursive Solution
public: 
    int fibo(int n) {
        if (n < 2) return n;
        return fibo(n-1) + fibo(n-2);
    }
}

int main () {
    
    return 0;
}