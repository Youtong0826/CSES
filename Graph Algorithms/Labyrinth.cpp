#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct pt{
    int x, y, t;
};

int n, m, sx, sy, ex, ey;
char mp[1001][1001];
char w[4] = {'R', 'D', 'L', 'U'};
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair<int, int> last[1001][1001];
queue<pt> q;

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(){
    mp[sx][sy] = '#';
    q.push({sx, sy, 0});

    while (q.size()){
        auto [x, y, t] = q.front();
        
        for (int i = 0; i < 4; i++){
            int px = x+d[i][0], py = y+d[i][1];
            if (in(px, py) && mp[px][py] != '#'){
                last[px][py] = {x, y};
                if (mp[px][py] == 'B')
                    return t+1;

                mp[px][py] = '#';
                q.push({px, py, t+1});
            }
        }
        q.pop();
    }
    
    return 0;
}

signed main(){
    Youtong;
    // freopen("test_input.txt", "r", stdin);
    
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
            if (mp[i][j] == 'A')
                sx = i, sy = j;

            else if (mp[i][j] == 'B')
                ex = i, ey = j;
        }
    }

    // cout << sx << ' ' << sy << '\n';

    int ans = bfs();

    if (ans){
        cout << "YES\n" << ans << '\n';

        string s = "";
        while (1){
            auto [x, y] = last[ex][ey];
            // cout << x << ' ' << y << '\n';
            for (int i = 0; i < 4; i++){
                if (x+d[i][0] == ex && y+d[i][1] == ey){
                    s.push_back(w[i]);
                }
            }

            if (x == sx && y == sy)
                break;

            ex = x, ey = y;
        }

        reverse(all(s));
        cout << s << '\n';
    }
    else 
        cout << "NO";
}