// Generate all binary strings without consecutive 1's

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    void solve(vector<string> &ans, string &str, int &k, int i = 0) {
        if (str.length() >= k) {
            ans.emplace_back(str);
            return;
        }

        if (i) {
            str.push_back('0');
            solve(ans, str, k);
        }
        else {
            str.push_back('0');
            solve(ans, str, k);
            str.pop_back();
            solve(ans, str, k, 1);
        }
    }

    vector<string> generateBinaryString(int &k) {
        string str = "";
        vector<string> ans;
        solve(ans, str, k);
        return ans;
    }
};

int main () {
    Solution obj;
    int k = 6;

    vector<string> ans = obj.generateBinaryString(k);
    
    for(auto &it: ans){
        cout << it << endl;
    }
    
    return 0;
}