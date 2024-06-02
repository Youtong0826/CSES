#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//
// 定義轉移式 dp[i][j] 長度為 i 第 i 個位置為 j 的組合數 
//
// dp[1][2] = 1
// dp[3][2] = 1
//
// dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]
//
const int maxn = 1e5+5, mod = 1e9+7;
int a[maxn], dp[maxn][105];

signed main(){
    Youtong;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (a[1])
        dp[1][a[1]] = 1;

    else {
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++){
        if (a[i]) { 
            dp[i][a[i]] = dp[i-1][a[i]] + dp[i-1][a[i]-1] + dp[i-1][a[i]+1];
            dp[i][a[i]] %= mod;
        }

        else {
            for (int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++){
        ans += dp[n][j];
        ans %= mod;
    }

    cout << ans << '\n';
}