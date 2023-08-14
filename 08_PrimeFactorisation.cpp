// PrimeFactorisation

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    vector<int> primeFactorisation(int n) {
        vector<int> ans;
        ans.emplace_back(1);

        int k = n; 
        while(!isPrime(k)) {
            
        }
        ans.emplace_back(k);
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