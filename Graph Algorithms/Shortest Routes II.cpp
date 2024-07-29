#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> dis;

signed main() {
    int n, m, q, a, b, c;
    cin >> n >> m >> q;
    dis.assign(n+1, vector<int>(n+1, 1e18));
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = min(dis[a][b], c);   
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = i+1; j <= n; j++) {
                if (j == k) continue;
                if (dis[i][j] > dis[i][k]+dis[k][j]) {
                    dis[i][j] = dis[j][i] = dis[i][k]+dis[k][j];
                }
            }
        }
    }

    while (q--) {
        cin >> a >> b;
        cout << ((dis[a][b] == 1e18)? -1: dis[a][b]) << '\n';
    }
}