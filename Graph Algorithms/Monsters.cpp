#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct pt{
    int x, y, t, p;// 1 人 0 怪物
};

int n, m;
char mp[1001][1001];
bool vis[1001][1001];
pii last[1001][1001];
vector<pt> mon;
queue<pt> q;

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(){
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (sz(q)){
        auto [x, y, t, p] = q.front();
        for (int i = 0; i < 4; i++){
            int px = x+d[i][0], py = y+d[i][1];
            if (in(px, py) && mp[px][py] != '#' && !vis[px][py]){
                if (p){
                    vis[px][py] = 1;
                    if (mp[px][py] == '.')
                        mp;
                }
            }
        }
    }
}

signed main(){
    Youtong;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
            if (mp[i][j] == 'A'){
                q.push({i, j, 1, 1});
                vis[i][j] = 1;
            }

            else if (mp[i][j] == 'B')
                mon.push_back({i, j, 1, 0});
        }
    }

    for (auto p: mon)
        q.push(p);
}