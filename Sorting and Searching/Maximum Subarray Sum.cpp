#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[200005];

signed main(){
    int n, a, ans;
    cin >> n;

    cin >> a;
    ans = dp[0] = a;
    for (int i = 1; i < n; i++){
        cin >> a;
        dp[i] = max(a, a+dp[i-1]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}