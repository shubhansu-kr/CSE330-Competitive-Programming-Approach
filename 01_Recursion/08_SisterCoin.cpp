// https://practice.geeksforgeeks.org/problems/sisters-and-coins2253/1

#include <bits/stdc++.h>
using namespace std ;

class Solution{
    // BruteForce: Recursion
    // TLE
public: 
    bool solve(int arr[], int &n, int m, int sum, int i){
        if (i < 0) return false;
        if (sum <= m) return sum == m;

        return solve(arr, n, m+arr[i], sum-arr[i], i-1) || solve(arr, n, m, sum, i-1);
    }

    int sisterCoin(int arr[], int n, int m){
        int sum = 0;
        for (int i = 0; i < n; ++i){sum += arr[i];}
        
        return solve(arr, n, m, sum, n-1);
    }
};

class Solution{
    // TLE: Time limit exceeded.
public: 
    bool solve(int arr[], int &n, int m, int sum, int i){
        if (i < 0) return false;
        if (sum == m) return true;

        sum -= arr[i];
        m += arr[i];
        if(solve(arr, n, m, sum, i-1)) return true;
        sum += arr[i];
        m -= arr[i];
        if(solve(arr, n, m, sum, i-1)) return true;

        return false;
    }

    int sisterCoin(int arr[], int n, int m){
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
        }

        if (sum <= m) return sum == m;
        
        return solve(arr, n, m, sum, n-1);
    }
};

int main () {
    
    return 0;
}