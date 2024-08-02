#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int n, m, a, b, c;
vector<int> dis, h; // h 為從節點 i 到終點的花費
vector<vector<pii>> g, g2; // g2 為反圖
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main() {
    cin >> n >> m;
    g.assign(n+1, {});
    g2.assign(n+1, {});
    h.assign(n+1, 1e18);
    dis.assign(n+1, 1e18);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    h[n] = 0;
    pq.push({0, n});
    while (pq.size()) {
        auto [v, c] = pq.top();
        pq.pop();
        for (auto [v2, c2]: g2[v]) {
            if (h[v2] > c+c2) {
                h[v2] = c+c2;
                pq.push({v2, h[v2]});
            }
        }
    }
}