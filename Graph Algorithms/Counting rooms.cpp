#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
char mp[1001][1001];
queue<pair<int, int>> q;

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy){
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    q.push({sx, sy});
    while (q.size()){
        auto [x, y] = q.front();
        for (int i = 0; i < 4; i++){
            int px = x+d[i][0], py = y+d[i][1];
            if (in(px, py) && mp[px][py] == '.'){
                mp[px][py] = '#';
                q.push({px, py});
            }
        }
        q.pop();
    }
}

int main(){
    Youtong;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == '.'){
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}