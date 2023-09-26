// Fibonacci Series: f(n) = f(n-1) + f(n-2): f(0) = 0, f(1) = 1

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce: Recursive Solution
public: 
    int fibo(int n) {
        if (n < 2) return n;
        return fibo(n-1) + fibo(n-2);
    }
}

int main () {
    
    return 0;
}