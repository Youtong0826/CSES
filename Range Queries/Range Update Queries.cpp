#include <bits/stdc++.h>
#define lowbit(x) x&-x
#define int long long
using namespace std;

const int maxn = 2e5+1;
int n, bit[maxn];

void update(int i, int v){
    for (; i <= n; i += lowbit(i))
        bit[i] += v;
}

void update(int l, int r, int v){
    update(l, v);
    update(r+1, -v);
}

int query(int i){
    int sum = 0;
    for (; i > 0; i -= lowbit(i))
        sum += bit[i];

    return sum;
}

signed main() {
    int q, o, x, y, u;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        update(i, i, u);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << bit[i] << '\n';

    while (q--){
        cin >> o;
        if (o == 1) {
            cin >> x >> y >> u;
            update(x, y, u);
        }
        else {
            cin >> u;
            cout << query(u) << '\n';
        }
    }
}