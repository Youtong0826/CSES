#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int maxn = 2e5+1;
bool vis[maxn];
vector<int> dis, from, ans;
vector<array<int, 3>> edges;

signed main() {
    int n, m, a, b, c, last = -1;
    cin >> n >> m;
    dis.assign(n+5, 1e18);
    from.resize(n+5);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [a, b, c]: edges){
            if (dis[b] > dis[a]+c){
                dis[b] = dis[a]+c;
                from[b] = a;
                if (i == n) {
                    last = a;
                }
            }
        }
    }

    if (last == -1){
        cout << "NO";
        return 0; 
    }
    
    int tmp = last;
    ans.push_back(tmp);
    while (!vis[last]) {
        vis[last] = 1;
        last = from[last];
        ans.push_back(last);
    }

    reverse(ans.begin(), ans.end());
    int f = 0;
    cout << "YES\n";
    for (auto x: ans) {
        if (f == 2) break;
        if (x == last) f++;
        cout << x << ' ';
    }
}