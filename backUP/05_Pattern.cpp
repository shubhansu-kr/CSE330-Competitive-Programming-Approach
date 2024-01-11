// Print the pattern

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    void printPattern(int n) {
        if (n > 19) {
            cout << "(__)" << endl;
            cout << "(oo)\\_______" << endl;
            cout << "(__)\\       )\\/\\ /\\ " << endl;
            cout << "||----w |   ||   ||" << endl;

            cout << endl;
            return;
        }

        int k = 2*n - 1;
        for(int i = 0; i < k; ++i){
            bool pr = false;
            int base = 5;

            int x = 1;
            for(int j = 0; j < k; ++j){
                if (abs(k/2 - i) == abs(k/2 - j)) pr = true;
                
                if (abs(k/2-i)-abs(k/2-j) == -1) pr = false;

                if (pr) {
                    if (x) {
                        if (base == 5) cout << "05";
                        else cout << base;

                        base += 5;
                    }
                    else {
                        cout << "  ";
                    }
                    x ^= 1;
                }
                else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};

int main () {
    Solution obj;
    for(int i = 0; i < 21; i++){
        cout << "\n\n";
        obj.printPattern(i);
        cout << "\n\n";
    }
    // obj.printPattern();
    return 0;
}