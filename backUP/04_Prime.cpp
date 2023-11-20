// Check

#include <bits/stdc++.h>
using namespace std ;

bool solve(string s, string num, int i){
    if (i == s.length()) return true;
    if (i > s.length()) return false;

    int l1 = num.length(); 
    int l2 = l1 + 1;
    
    string s1, s2;
    bool a = false, b=false;
    if (i + l1 <= s.length()){
        s1 = s.substr(i, l1);

        if (stringToInteger(s1) == stringToInteger(num)+1) a = solve(s, s1, i+l1);
        if (a) return true;
    }
    if (i + l2 <= s.length()) {
        s2 = s.substr(i, l2);
        if (stringToInteger(s2) == stringToInteger(num)+1) b = solve(s, s2, i+l2);

        if (b) return true;
    }

    return a || b;
}

int stringToInteger(string sr){
    if(s.length() < 1) return -1;
    if (s[0] == '0') return -1;

    int num = 0;
    for(auto &it: sr){
        num = (num*10 + (it-'0'));
    }

    return num;
}

int main () {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        while(n--){
            string s;
            cin >> s;

            int x = -1;
            for(int len = 1; len < s.length(); ++len) {
                string sub = s.substr(0, len);
                int nums = stringToInteger(sub);

                if (nums == -1) continue;
                else {
                    if (solve(s, nums, len)) x = nums;
                }
            }

            if (x == -1){
                cout << "NO" << endl;
            }
            else {
                cout << "YES " << x << endl;
            }
        }
    }
    return 0;
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