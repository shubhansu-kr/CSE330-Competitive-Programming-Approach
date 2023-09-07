// Given a number n, find the min number greater than or equal to n which is
// a happy number

// https://practice.geeksforgeeks.org/problems/next-happy-number4538/1

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Brute Force: Use Loops 
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

    int nextHappyNumber(int n) {
        while(n++){
            if(isHappy(n)) return n;
        }
        return -1;
    }
};

int main () {
    
    return 0;
}