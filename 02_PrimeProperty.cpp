// Check the property of primes

#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n)
{
    if (n < 2) return false;

    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i*i <= n; i = i + 6)
    {
        if (n % i == 0) return false;
    }

    return true;
}

void collectPrimes(vector<int> &primes)
{
    primes.emplace_back(2);
    primes.emplace_back(3);
    for (int i = 5; i < 1000; ++i)
    {
        if (isPrime(i)) primes.emplace_back(i);
        ++i;
    }
}

int main()
{
    vector<int> primes;
    collectPrimes(primes);

    for(auto &it: primes) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}