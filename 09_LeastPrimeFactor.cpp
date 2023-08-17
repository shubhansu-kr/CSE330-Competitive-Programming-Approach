// Find the least prime factor of all the number from 2 to n.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public: 
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n+1, -1);

        // Prime factor of all the prime number is 2
        for (int i = 2; i <= n; ++i)
        {
            ans[i] = returnPrime(i);
        }

        return ans;
    }

    int returnPrime(int n)
    {
        if (n < 2) return -1;

        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;

        for (int i = 5; i*i <= n; i = i + 6)
        {
            if (n % i == 0 ) return i;
            if (n % (i+2) == 0) return i+2;
        }

        return n;
    }
};

int main () {
    
    return 0;
}