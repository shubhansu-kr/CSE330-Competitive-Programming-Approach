// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Iteratice
public:
    // string solve(string s, int n)
    // {
    // }

    string decodedString(string s)
    {
        bool loop = true, t = 0;
        while (loop)
        {
            loop = false;
            for (int i = t; i < s.length(); ++i)
            {
                int count = 0, len = 0;
                if (s[i] >= '0' && s[i] <= '9')
                {
                    int j = i + 1, len = 0;
                    do
                    {
                        if (s[j] == '[')
                            ++count;
                        else if (s[j] == ']')
                            --count;

                        ++len;
                        ++j;
                    } while (count);

                    len = j - i - 2;
                    string sub = s.substr(i + 2, len), ans = "";
                    for (int i = 0; i < s[i] - '0'; ++i)
                    {
                        ans += sub;
                    }
                    loop = true;

                    t = i;
                    
                    s.replace(i, j-i + 1, ans);
                    
                    break;
                }
            }
        }
        return s;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
