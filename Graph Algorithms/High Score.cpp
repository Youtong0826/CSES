#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2501;

vector<int> dis;
vector<vector<int>> g;
vector<array<int, 3>> edges;

signed main() {
    int n, m, a, b, c;
    cin >> n >> m;
    g.assign(n+1, {});
    dis.assign(n+1, -1e18);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            dis[b] = c;
        }
        edges.push_back({a, b, c});
    }

    

    for (int i = 1; i < n; i++) {
        for (auto [a, b, c]: edges) {
            if (dis[b] < dis[a]+c) {
                dis[b] = dis[a]+c;
            }
        }
    }

    cout << dis[n];
}