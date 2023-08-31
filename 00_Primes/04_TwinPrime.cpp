// A pair of prime number is said to be twin prime if difference between the primes is 2.

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Store prev prime.
public: 
    int countTwinPrime (int n) {
        int count = 0;

        // whenver you get a prime number check the prev found prime for difference of 2
        // dont call the prime function twice.
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i), isPrime(i+2)) {
                ++count;
                cout << i << " " << i+2 << " \n";
            }
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
public: 
    int countTwinPrime (int n) {
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i), isPrime(i+2)) {
                ++count;
                cout << i << " " << i+2 << " \n";
            }
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

int main () {
    Solution obj;
    cout << "\n\n\n\n count : " <<  obj.countTwinPrime(1000);
    return 0;
}