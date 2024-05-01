#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int maxn = 1e5+1;
int n, m, a, b;
int last[maxn];
bool vis[maxn];
vector<vector<int>> g;

int bfs(){
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (q.size()){
        auto [t, idx] = q.front();
        for (auto i: g[idx]){
            if (!vis[i]){
                vis[i] = 1;
                last[i] = idx;
                if (i == n)
                    return t+1;

                q.push({t+1, i});
            }
        }
        q.pop();
    }

    return 0;
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

    int ans = bfs();
    if (ans){
        cout << ans << '\n';

        vector<int> d({n});
        int t = n;
        while (t != 1){
            // cout << last[t] << '\n';
            d.pb(last[t]);
            t = last[t];
        }

        reverse(all(d));

        for (auto i: d)
            cout << i << ' ';
    }
    else
        cout << "IMPOSSIBLE";
}