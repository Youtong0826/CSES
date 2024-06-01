#include <bits/stdc++.h>
using namespace std;

// dp[l][r] = [l, r] 先手的最佳策略
// dp[l][r] = max(a[l, r] - a[l]+dp[l+1, r], a[l, r]-a[r]+dp[l, r-1]);

const int maxn = 5e3+1;
int arr[maxn], pre[maxn], dp[maxn][maxn];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1]+arr[i];
    }

    for (int)
}