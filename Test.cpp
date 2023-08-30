// 

#include <bits/stdc++.h>
using namespace std ;

long long findExecutionTime (vector<int> execution){
    unordered_map<int, int> fx;
    for (int i = 0; i < execution.size(); ++i)
    {
        fx[execution[i]] = execution[i];
    }

    long long ans = 0;
    for (int i = 0; i < execution.size(); ++i)
    {
        ans += fx[execution[i]];
        cout << ans << " " << fx[execution[i]] << endl;
        fx[execution[i]] = (fx[execution[i]]+1)/2;
    }
    
    return ans;
}

int findMinInterference(string serverType){
    int ans = 0;
    int i = 0;
    while (serverType[i] == '?'){
        ++i;
    }
    char current = serverType[i++];
    while(i < serverType.size()){
        if (serverType[i] != '?' && serverType[i] != current){
            ++ans;
            current = serverType[i];
        }
        ++i;
    }
    return ans;
}

int main () {
    string s = "";
    cout << findMinInterference(s);

    return 0;
}