#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

const int maxn = 1e3+5;
int dp[maxn][maxn];
char mp[maxn][maxn];

signed main(){
    Youtong;
    int n, mod = 1e9+7;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> mp[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 && j == 1){
                if (mp[i][j] == '*')
                    dp[i][j] = 0;

                else 
                    dp[i][j] = 1;
            }

            else if (mp[i][j] == '*')
                dp[i][j] = 0;
            
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

            dp[i][j] %= mod;
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    cout << dp[n][n];
}