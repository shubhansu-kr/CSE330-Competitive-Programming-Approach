// Check if a number can be written as a sum of k prime numbers.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce: Recursion
public: 
    bool primeKSum(int &n, int k) {
        // get all the primes less than n;
        vector<int> primes = sieveOfErastosthenes(n);
        int size = primes.size();

        if (k > size) return false;

        // now the problem becomes... if we get n as a sum of k elements 
        // in given array.

        return solve(primes, k, n, size-1);

    }

    bool solve(vector<int> &nums, int k, int &n, int i) {
        if (k == 0) return n == 0;
        if (i < 0 || n < 0) return false;

        // pick 
        n -= nums[i];
        if (solve(nums, k-1, n, --i)) return true;
        n += nums[i];
        if (solve(nums, k, n, i-1)) return true;

        return false;
    }

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