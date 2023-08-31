// https://practice.geeksforgeeks.org/problems/transform-to-prime4635/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long minNumber(long long arr[],long long N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    cout << minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Test Cases Passed: 
// 352 /440
// Time Limit Exceeded

// Your program took more time than expected.
// Expected Time Limit : 2.49sec
// Hint : Please optimize your code and submit again.

vector<bool> sieveOfErastosthenes(ll &n) {
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
    return primes;
}

long long minNumber(long long arr[], long long N)
{
    ll sum = 0;
    for (int i = 0; i < N; ++i) { sum += arr[i]; }

    ll k = sum*2;
    vector<bool> primes =  sieveOfErastosthenes(k);  
    
    for (int i = 0; i < k; ++i)
    {
        if (primes[sum+i]) return i;
    }
    
    return 0;
}


