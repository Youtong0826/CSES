#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int dp[1000005], mod = 1e9+7;

signed main(){
    Youtong;
    int n;
    cin >> n;
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i && j <= 6; j++){
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }

    cout << dp[n];
}