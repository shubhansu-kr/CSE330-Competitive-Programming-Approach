// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution1{  
    // Recursion: Memoization
public:
    bool solve(vector<int> &arr, vector<vector<int>> &dp, int sum, int i) {
        if (sum == 0) return true;
        if (i < 0 || sum < 0) return false;
        
        if (dp[i][sum] != -1) return dp[i][sum];

        if (solve(arr, dp, sum-arr[i], i-1)) return dp[i][sum] = true;
        if (solve(arr, dp, sum, i-1)) return dp[i][sum] = true;

        return dp[i][sum] = false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));

        return solve(arr, dp, sum, arr.size()-1);
    }
};

class Solution{  
    // Recursion:  
public:
    bool solve(vector<int> &arr, int sum, int i) {
        if (sum == 0) return true;
        if (i < 0 || sum < 0) return false;
        
        if (solve(arr, sum-arr[i], i-1)) return true;
        if (solve(arr, sum, i-1)) return true;

        return false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        return solve(arr, sum, arr.size()-1);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends