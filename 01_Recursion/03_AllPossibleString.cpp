// Print all possible strings of length k that can be formed from a set o n character

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 

    void solve(vector<string> &ans, string &str, vector<char> &collection, int &k) {
        if (str.length() >= k) {
            ans.emplace_back(str);
            return;
        }

        for (int j = 0; j < collection.size(); ++j)
        {
            str.push_back(collection[j]);
            solve(ans, str, collection, k);
            str.pop_back();
        }
        
        return;
    }

    vector<string> findPossibleStrings(vector<char> &collection, int &k) {
        string str = "";
        vector<string> ans;
        solve(ans, str, collection, k);
        return ans;
    }
};

int main () {
    Solution obj;

    vector<char> collection = {'a', 'b', 'c'};
    int k = 4;

    vector<string> ans = obj.findPossibleStrings(collection, k);

    for(auto &it: ans) {
        cout << it << endl;
    }
    
    return 0;
}