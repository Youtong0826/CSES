#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2501;
vector<bool> vis1, vis2;
vector<int> dis;
vector<vector<int>> g, g2;
vector<array<int, 3>> edges;

void dfs(int idx, vector<bool> &vis, vector<vector<int>> &g) {
    if (vis[idx])
        return;
    
    vis[idx] = 1;
    for (auto x: g[idx]){
        dfs(x, vis, g);
    }
}

signed main() {
    int n, m, a, b, c;
    cin >> n >> m;
    
    g.assign(n+1, {});
    g2.assign(n+1, {});
    dis.assign(n+1, 1e18);
    vis1.resize(n+1);
    vis2.resize(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            dis[b] = -c;
        }
        g[a].push_back(b);
        g2[b].push_back(a);
        edges.push_back({a, b, -c});
    }

    if (n == 1 && m == 1) {
        auto [a, b, c] = edges[0];
        cout << (c > 0)? 0: -1;
    }

    dfs(1, vis1, g);
    dfs(n, vis2, g2);

    for (int i = 1; i <= n; i++) {
        for (auto [a, b, c]: edges) {
            if (dis[b] > dis[a]+c) {
                if (i == n && vis1[b] && vis2[b]){
                    cout << -1;
                    return 0;
                }
                dis[b] = dis[a]+c;
            }
        }
    }

    cout << -dis[n];
}