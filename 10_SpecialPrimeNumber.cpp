// A number n is called special prime if n is prime, n/10 is also prime, n/100 is also prime
// untill n/10*d is also prime where d is no. of digits -1;

// eg. 473 -> check for 473, 47 and 4;

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public: 
    bool isSpecialPrime(int n) {
        int k = n;
        
        while(k) {
            if (!isPrime(k)) return false;
            k /= 10;
        }

        return true;
    }

    bool isPrime(int n)
    {
        if (n < 2) return false;

        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i*i <= n; i = i + 6)
        {
            if (n % i == 0 || n % (i+2) == 0) return false;
        }
        
        return true;
    }
};

int main () {
    
    return 0;
}