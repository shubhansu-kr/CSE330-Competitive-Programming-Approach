// Count Sort

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    vector<int> countSort(vector<int> &nums){
        int max = INT_MIN, min = INT_MAX;
        for(auto &it: nums) {
            if (it > max) max = it;
            if (it < min) min = it;
        }
        
        int len = (max - min + 1);
        vector<int> count(len);

        // index 0 will be representing element `min`.
        // we will have to calculate shift.
        int shift = 0;

        if (min < 0) {shift = min;}
        else if (min > 0) {shift = -min;}

        for(auto &it: nums) {
            count[it+shift]++;
        }

        vector<int> ans;
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < count[i]; ++j) {
                ans.emplace_back(i-shift);
            }
        }

        return ans;
    }
};

int main () {
    
    Solution obj;
    vector<int> nums = {-1, -3, -5, -3, 0, 0, 4, 3, 3, 3, 4};
    vector<int> ans = obj.countSort(nums);
    for(auto &it: ans) {
        cout << it << " ";
    }
    return 0;
}