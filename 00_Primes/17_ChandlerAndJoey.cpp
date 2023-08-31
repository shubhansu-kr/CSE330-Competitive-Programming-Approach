// https://www.hackerearth.com/problem/algorithm/chandler-and-joey/

#include <bits/stdc++.h>
using namespace std ;

int findgcd(vector<int> &nums) {
    int ans = gcd(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i)
    {
        if (ans == 1) return ans;
        ans = gcd(ans, nums[i]);
    }
    return ans;
}

pair<int, int> findWinner(vector<int> &nums){

    unordered_set<int> st;

    // The logic is we can get the numbers in the range of [gcd, max] at an interval of gcd(array);
    int maxi = INT_MIN;
    for(auto &it: nums) {
        maxi = max(maxi, it);
        st.insert(it);
    }

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int k = maxi / findgcd(nums);

    int insertions = k-n;
    
    if (n-k == 0) {
        return pair<int, int>({1, 0}); 
    }

    int chandler = 0, joey = 0;
    // 1: Chandler || 0: Joey

}

int main () {
    
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> nums;
        while(n--) {
            cin >> x;
            nums.emplace_back(x);
        }
        pair<int, int> winner = findWinner(nums);
        if (winner.first){
            // chandler wins 
        }
        else {
            // Joey wins 
        }

    }
    return 0;
}