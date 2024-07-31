#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<int> dis;
vector<array<int, 3>> edges;

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    dis.assign(n+1, 1e18);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    dis[1] = 0;
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [a, b, c]: edges){
            if (dis[b] > dis[a]+c){
                dis[b] = dis[a]+c;
                if (i == n) {
                    f = 1;
                }
            }
        }
    }
    
}