// https://leetcode.com/problems/additive-number/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool solve(string &num, string curr, string prev, int i) {
        
    }

    bool isAdditiveNumber(string num) {
        for (int len = 1; len < num.size(); ++len)
        {
            if (solve(num, num.substr(0, len), "", len)) return true;
        }
        return false;
    }
};

int main () {
    
    return 0;
}