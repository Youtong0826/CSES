#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+1;
int mp[maxn][maxn];

int main() {
    int n, q, x1, y1, x2, y2;
    char c;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            mp[i][j] = mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1]; 
            if (c == '*')
                mp[i][j]++;
            // cout << mp[i][j] << ' ';
        }
        // cout << '\n';
    }
    // cout << '\n';

    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << mp[x2][y2] - mp[x1-1][y2] - mp[x2][y1-1] + mp[x1-1][y1-1] << '\n';
    }
}