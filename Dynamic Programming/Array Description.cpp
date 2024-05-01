#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


// 定義轉移式 dp[i][j] 長度為 i 第 i 個位置為 j 的組合數
//
const int maxn = 1e5+5;
int a[maxn], dp[105][maxn];

signed main(){
    Youtong;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    

}