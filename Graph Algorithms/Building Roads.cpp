#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, a, b, ans = 0;
vector<vector<int>> g;
vector<int> c;
bool vis[100005];

void dfs(int idx){
    if (vis[idx])
        return;

    vis[idx] = 1;
    for (auto i: g[idx])
        dfs(i);
}

signed main(){
    Youtong;
    cin >> n >> m;
    g.resize(n+1, {});

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
            c.pb(i);
            ans++;
        }
    }

    cout << ans-1 << '\n';
    for (int i = 1; i < sz(c); i++)
        cout << c[i-1] << ' ' << c[i] << '\n';
    
}