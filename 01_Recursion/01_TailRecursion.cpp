// TailRecursion: When the recursive function is the last executed statement of the fxn,
// it is called tail recursion. 

#include <bits/stdc++.h>
using namespace std ;

// Tail Recursion
void tail(int n) {
    if (n < 0) return;
    cout << n << " ";
    tail(n-1);
}

// Converting the tail recursive function to iterative is very simple. 
void tail(int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ";
    }
}

int main () {
    
    return 0;
}