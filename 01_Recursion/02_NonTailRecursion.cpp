// NonTail Recursion: When the last executed statement is not the recursive fxn call, it is 
// called non tail recursion.

#include <bits/stdc++.h>
using namespace std ;

int nonTail(int n) {
    if (n < 1) return 1;

    return n * nonTail(n-1);
}

// Non Tail function cannot be converted into an iterative one easily, we have to first 
// convert the non tail function to tail function. 

// To convert the nonTail function to Tail recursive function: We add an extra parameter to the 
// function call

// eg. 
int tail(int n, int result = 1) {
    if (n < 1) return 1; 

    return tail(n-1, result * n);
}

void iterative(int n) {
    int result = 1;
    for (int i = n; i > 0; --i)
    {
        result = result * i;
    }
    
}

int main () {
    
    return 0;
}