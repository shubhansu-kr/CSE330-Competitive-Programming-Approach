// Sieve of Erastosthenes: Create a array of size n.
// Initially all the elements are initialised with true value: representing all element as prime.
// Now, start from element 2, consider it prime, so make all the multiples of 2 false.
// Again, start from element 3, consider it prime, so make all the multiple of 3 false.
// Keep repeating the process.... 
// This way we will get all the primes from 0 to n.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public: 
    vector<int> sieveOfErastosthenes(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i <= n; ++i)
        {
            if (primes[i]) {
                int index = i * 2;
                while(index <= n) {
                    primes[index] = false; 
                    index += i;
                }
            }
        }
        
        // primes vector is sieve of erastosthenes.
        vector<int> ans;
        for (int i = 0; i <= n; ++i)
        {
            if (primes[i]) ans.emplace_back(i);
        }
        
        return ans;
    }
};

int main () {
    
    return 0;
}