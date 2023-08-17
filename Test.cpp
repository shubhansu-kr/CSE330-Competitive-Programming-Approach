// Test

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperation(vector<int> &A, int B) {
        if (B > A.size()) return 0;

        unordered_set<int> st;
        for(auto &it: A) {st.insert(it);}

        int D = st.size();

        if (D < B) return 0;
        return abs(B-D);
    }
};

int main()
{

    return 0;
}