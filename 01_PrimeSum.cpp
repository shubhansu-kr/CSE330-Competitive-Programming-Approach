// Given a number, find two prime numbers which sum to the given number.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public: 
    pair<int, int> findPrimeSum(int n) {
        if (n < 4) return pair<int, int>({-1, -1});

        if (n % 2) {
            if (isPrime(n-2)) return pair<int, int>({2, n-2});
            else return pair<int, int>({-1, -1});
        } 

        // Two Pointer
        int k = n/2;

    }

    bool isPrime(int n) {
        if (n < 2) return false;
        
        for (int i = 2; i < n/2; ++i)
        {
            if (n % i == 0) return false;
        }        

        return true;
    }
};

int main () {
    
    return 0;
}