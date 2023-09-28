// 0-1 KnapSack : Complete or nothing

#include <bits/stdc++.h>
using namespace std ;

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