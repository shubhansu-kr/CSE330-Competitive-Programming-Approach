// Twisted prime: A number is called a twisted prime if it is prime and it's reverse is also prime.

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    bool isTwistedPrime(int n) {
        int rev = 0, temp = n;
        while(temp) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        return isPrime(rev) && isPrime(n);
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