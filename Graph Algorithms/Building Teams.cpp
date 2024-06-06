#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int maxn = 1e5+1;
int n, m, a, b;
int team[maxn];
bool f = 0;
vector<vector<int>> g;

void dfs(int idx, int c){
    if (team[idx])
        return;
    
    team[idx] = c;
    c = (c == 1? 2: 1);
    for (auto i: g[idx]){
        dfs(i, c);
        if (f) return;
    }

    for (auto i: g[idx]){
        if (team[i] == team[idx]){
            f = 1;
            return;
        }
    }
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
        if (!team[i]){
            dfs(i, 1);
        }
    }

    if (!f){
        for (int i = 1; i <= n; i++)
            cout << team[i] << ' ';
    }
    
    else
        cout << "IMPOSSIBLE";

}