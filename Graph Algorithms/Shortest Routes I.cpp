#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define l first 
#define r second
using namespace std;

const int maxn = 2e5+2;
int dis[maxn];
bool vis[maxn];

priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<vector<pii>> g;

signed main(){
    int n, m, a, b, c;
    cin >> n >> m;
    g.assign(n+1, {});
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    for (int i = 0 ;i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    pq.push({0, 1LL});
    dis[1] = 0;
    while (pq.size())
    {
        auto [d, v] = pq.top();
        pq.pop();
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto [e, c]: g[v]) {
            if (dis[e] > dis[v]+c) {
                dis[e] = dis[v]+c;
                pq.push({dis[e], e});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';   
}