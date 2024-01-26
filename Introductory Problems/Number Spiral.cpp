#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;

signed main(){
    io;
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        int mn = max(a, b), mid = mn*(mn-1)+1;
        mid += (mn % 2)? b-a: a-b;
        cout << mid << '\n';
    }
}