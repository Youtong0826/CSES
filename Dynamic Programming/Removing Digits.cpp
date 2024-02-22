#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

vector<int> dp;

signed main(){
    Youtong;
    int n;
    cin >> n;
    dp.assign(n+1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j > 0; j /= 10){//27 20
            dp[i] = min(dp[i], dp[i - j % 10]+1);
        }
    }
    
    cout << dp[n];
}