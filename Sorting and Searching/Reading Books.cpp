#include <bits/stdc++.h>
#define int long long
#define Youtong ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

signed main() {
    Youtong;
    int n, sum = 0, mx = 0, t;
    cin >> n;
    while (n--) {
        cin >> t;
        sum += t;
        mx = max(mx, t);
    }
    cout << max(sum, mx * 2);
}