// If n is a prime number, then for every k, where k belongs to 1 <= k <= n, then k^(n-1) % n = 1;
// For prime it will always give true, but for composite it may give true | false;

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPrimeFermetWay(int n) {
        if (n < 2) return false;
        if (n < 4) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        int k = 50, a = n/4;
        while (k--) {
            if (a < 2 || a > n-1) {
                break;
            }

            double x = pow((n/2)+a, n-1);
            double y = pow((n/2)-a, n-1);

            if ((int)x % n != 1) return false;
            if ((int)y % n != 1) return false;

            a += a/2;
        }
        
        return true;
    }
};

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

int main () {

    Solution obj;
    
    int count = 0, v = 0;

    for (int i = 0; i < 1000; ++i)
    {
        if (obj.isPrimeFermetWay(i)) {
            ++count;
            cout << i << " ";
        }

        if (isPrime(i)) ++v;
    }

    cout << endl << "No. of primes = " << count << endl;

    // Verify the solution.
    if (count == v) {
        cout << "Fine\n";
    }
    else {
        cout << "Err\n";
    }
    
    
    return 0;
}