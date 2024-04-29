#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mod = 1e9+7;
    cin >> n;

    int t = 1;
    while (n--){
        t <<= 1;
        t %= mod;
    }
    
    cout << t;
}