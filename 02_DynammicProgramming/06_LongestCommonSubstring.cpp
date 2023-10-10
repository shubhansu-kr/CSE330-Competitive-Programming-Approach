// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Wrong Answer 
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j) {
        if (i < 0 || j < 0) return 0;

        int match = 0;
        while(i < nums1.size() && j < nums2.size()){
            if (nums1[i++] == nums2[j++]) ++match;
            else break;
        }

        int recursion = max(solve(nums1, nums2, i-1, j), solve(nums1, nums2, i, j-1));

        return max(match, recursion);
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        return solve(nums1, num2, m-1, n-1);
    }
};

int main () {
    
    return 0;
}