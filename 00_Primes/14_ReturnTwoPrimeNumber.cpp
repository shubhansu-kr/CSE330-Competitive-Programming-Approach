// https://practice.geeksforgeeks.org/problems/return-two-prime-numbers2509/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        vector<bool> primes = sieveOfErastosthenes(N);
        vector<int> ans;
        if (N % 2) {
            // Odd Number... 
            if (primes[N-2]) {
                ans.emplace_back(2);
                ans.emplace_back(N-2);
            }
        }
        else {
            // Even Number...
            for (int i = 2; i <= N/2; i++)
            {
                if (primes[i] && primes[N-i]) {
                    ans.emplace_back(i);
                    ans.emplace_back(N-i);

                    break;
                }
            }
        }
        return ans;
    }

    vector<bool> sieveOfErastosthenes(int &n) {
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
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends