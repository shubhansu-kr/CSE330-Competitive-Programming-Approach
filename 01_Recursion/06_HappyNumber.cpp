// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // In one digit numbers, only 1 and 7 are the happy number, so if we get to
    // a single digit number we can return false if it's not 1 or 7.
public:
    bool solve(int n, unordered_set<int> &st) {
        if (n == 1) return true;
        if (st.count(n)) return false;

        st.insert(n);

        int num = 0;
        while(n) {
            num += pow((n%10), 2);
            n /= 10;
        }

        return solve(num, st);
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        for (int i = 2; i < 10; ++i)
        {
            if (i == 7) continue;
            st.insert(i);
        }
        
        return solve(n, st);
    }
};

int main () {
    
    return 0;
}