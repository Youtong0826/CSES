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
vector<vector<int>> g;
vector<int> ans;
void dfs(int idx, int fat){
    if (last[idx]){
        ans.push_back(idx);
        while (fat != idx){
            ans.push_back(fat);
            fat = last[fat];
        }
        ans.push_back(idx);
        
        return;
    }
    // cout << idx << '\n';
    last[idx] = fat;

    for (auto i: g[idx]){
        if (i != fat){
            // cout << i << '\n';
            dfs(i, idx);
            if (sz(ans))
                return;
        }
    }
}

signed main(){
    // Youtong;
    cin >> n >> m;
    g.resize(n+1, {});
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 1; i <= n; i++){
        if (sz(ans))
            break;

        if (!last[i]){
            // last[i] = i;
            dfs(i, i);
        }
    }

    if (sz(ans)){
        cout << sz(ans) << '\n';
        for (auto i: ans)
            cout << i << ' ';
    }
    else
        cout << "IMPOSSIBLE\n";
}