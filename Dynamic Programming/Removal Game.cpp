#include <bits/stdc++.h>
#define int long long
using namespace std;

// dp[l][r] = 區間 [l, r] 最佳策略
// dp[l][r] = max(sum(l, r) - dp[l+1][r], sum(l, r)-dp[l, r-1]);

const int maxn = 5e3+1;
int arr[maxn], pre[maxn], dp[maxn][maxn];

signed main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1]+arr[i];
        dp[i][i] = arr[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1, p = pre[j]-pre[i-1];
            dp[i][j] = max(p - dp[i+1][j], p - dp[i][j-1]);
            // cout << i << ' ' << j << ' ' << p << ' ' << dp[i][j] << '\n';
        }
    }

    cout << dp[1][n] << '\n';
}