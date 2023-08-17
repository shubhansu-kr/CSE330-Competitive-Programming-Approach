// PrimeFactorisation

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    vector<int> primeFactorisation(int n) {
        vector<int> ans;
        ans.emplace_back(1);

        int k = n; 
        while (k % 2 == 0) {
            ans.emplace_back(2);
            k /= 2;
        }

        for (int i = 3; i*i < k; ++i)
        {
            if (k % i == 0) {
                ans.emplace_back(i);
                k /= i;
                --i;
            }
            else {
                ++i;
            }
        }
        
        if (k > 2) ans.emplace_back(k);

        return ans;
    }
};

int main () {
    
    return 0;
}