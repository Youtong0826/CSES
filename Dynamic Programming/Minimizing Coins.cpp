#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

vector<int> dp, coin;

//dp[i] 總和為i時所需的最小硬幣數
//coin[i] 表示選中的硬幣
//dp[i] = min(dp[i], dp[i-coin[j]] + 1)
//

signed main(){
    Youtong;
    int n, k;
    cin >> n >> k;
    dp.assign(k+1, INT_MAX);
    coin.resize(n);
    for (auto &x: coin)
        cin >> x;

    dp[0] = 0;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i - coin[j] >= 0){
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }

    if (dp[k] == INT_MAX)
        cout << -1;

    else
        cout << dp[k];
}