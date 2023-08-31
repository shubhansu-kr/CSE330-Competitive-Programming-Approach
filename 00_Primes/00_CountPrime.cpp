// https://leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // TLE
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        int  count = 1;
        for (int i = 3; i < n; ++i)
        {
            if (isPrime(i)) ++count;
            ++i;
        }
        return count;
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
class Solution {
    // TLE
public:
    int countPrimes(int n) {
        if (n < 3) return 0;

        int  count = 1;
        for (int i = 3; i < n; ++i)
        {
            if (isPrime(i)) ++count;
            ++i;
        }
        return count;
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

class Solution {
public:
    // BruteForce: TLE
    int countPrimes(int n) {
        if (n < 3) return 0;

        int  count = 1;
        for (int i = 3; i < n; ++i)
        {
            if (isPrime(i)) ++count;
            ++i;
        }
        return count;
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        
        for (int i = 2; i < n/2; ++i)
        {
            if (n % i == 0) return false;
        }        

        return true;
    }

    bool isFullPrime(int n) {
        // A number 'n' is called full prime if n itself is prime and all it's digits
        // are also prime. eg. 37 is prime and 3, 7 are also prime so 37 is full prime.
        // eg 41 is a prime but not a full prime because 4 is not prime. 

        if (!isPrime(n)) return false;

        // while(n) {
        //     if (!isPrime(n%10)) return false;
        //     n /= 10;
        // }

        unordered_set<int> primes;
        primes.insert(2);
        primes.insert(3);
        primes.insert(5);
        primes.insert(7);

        while(n) {
            if (!primes.count(n%10)) return false;
            n /= 10;
        }
        
        return true;
    }
};

int main () {
    
    return 0;
}