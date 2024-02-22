#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

//dp[i][j] 考慮前 i 本書 在 j 金額內得到的最大頁數

vector<int> cost, books;
vector<vector<int>> dp;
signed main(){
    Youtong;
    int n, x;
    cin >> n >> x;

    cost.resize(n+1);
    books.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 1; i <= n; i++)
        cin >> books[i];

    dp.assign(n+1, vector<int>(x+1));
    for (int i = 1; i <= n; i++){
        int c = cost[i], b = books[i];
        for (int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if (c <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-c] + b);
        }
    }

    cout << dp[n][x];
}