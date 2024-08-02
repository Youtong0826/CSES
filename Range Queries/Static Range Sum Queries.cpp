#include <bits/stdc++.h>
#define int long long
using namespace std;

int pre[200005];

signed main(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        if (i != 1)
            pre[i] += pre[i-1];
    }

    int x, y;
    pre[0] = 0;
    while (q--){
        cin >> x >> y;
        cout << pre[y] - pre[x-1] << '\n';
    }
    
}