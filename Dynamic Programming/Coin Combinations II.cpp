#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

vector<int> dp, c;

signed main(){
    Youtong;
    int n, x, mod = 1e9+7;
    cin >> n >> x;
    dp.assign(x+1, 0);
    c.resize(n);
    for (auto &x: c)
        cin >> x;

    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= x; j++){
            if (j - c[i] >= 0){
                dp[j] += dp[j - c[i]] % mod;
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x];
}