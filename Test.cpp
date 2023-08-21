// Test

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public: 
    int countPairs(vector<int> &A) {
        int n = A.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (2 * (A[i] | A[j]) + (A[i] ^ A[j]) >= A[i] + A[j]) {
                    ++count;
                }
            }
        }

        return count;
    }
};

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