#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    io;
    string s;
    cin >> s;
    char last = s[0];
    int t = 1, mn = INT_MIN;
    for (int i = 1; i < s.size(); i++){
        t = (last == s[i])? t+1: 1;
        mn = max(mn, t);
        last = s[i];
    }

    cout << max(mn, t);
}