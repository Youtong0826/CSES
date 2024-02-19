#include <bits/stdc++.h>
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> c, dp;

signed main(){
    Youtong;
    int n, x, mod = 1e9+7;
    cin >> n >> x;
    c.resize(n);
    dp.assign(x+1, 0);
    for (auto &x: c)
        cin >> x;

    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0){
                dp[i] += dp[i-c[j]] % mod;
                dp[i] %= mod;
            }
        }
    }

    cout << dp[x];
}