// Fibonacci Series: f(n) = f(n-1) + f(n-2): f(0) = 0, f(1) = 1

#include <bits/stdc++.h>
using namespace std ;

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