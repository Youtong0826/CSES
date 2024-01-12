#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;

signed main(){
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        int mn = max(a, b), mid = mn*(mn-1)+1, d = abs(a-b);
        
        if ((a < b && !(b % 2)) || (a > b && a % 2))
            mid -= d;
        
        else if ((a < b && b % 2) || (a > b && !(a % 2)))
            mid += d;

        cout << mid << '\n';
    }
}