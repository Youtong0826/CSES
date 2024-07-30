#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int n, m, a, b, c;
const int LMX = 1e18;
vector<bool> vis;
vector<int> dis;
vector<vector<pair<int, int>>> g;
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main() {
    cin >> n >> m;
    g.assign(n*2+2, {});
    vis.resize(n*2+2);
    dis.assign(n*2+2, LMX);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[a+n].push_back({b+n, c});
        g[a].push_back({b+n, c/2});
    }

    
    dis[1] = 0;
    pq.push({dis[1], 1});
    while (pq.size()) {
        auto [c, v] = pq.top();
        pq.pop();
        if (vis[v])
            continue;

        vis[v] = 1;
        for (auto [u, d]: g[v]) {
            if (dis[u] > dis[v]+d) {
                dis[u] = dis[v]+d;
                pq.push({dis[u], u});
            }
        }
    }

    cout << dis[n+n] << '\n';
}