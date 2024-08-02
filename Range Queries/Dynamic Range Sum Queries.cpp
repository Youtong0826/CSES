#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x&-x
using namespace std;

const int maxn = 2e5+2;
int n, q, arr[maxn], bit[maxn];

void build(int x, int v) {
    for (; x <= n; x+= lowbit(x))
        bit[x] += v;
}

void update(int x, int v) {
    int temp = v-arr[x];
    arr[x] = v;
    for (; x <= n; x+= lowbit(x))
        bit[x] += temp;
}

int query(int p) {
    int sum = 0;
    for (; p > 0; p -= lowbit(p)) {
        sum += bit[p];
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l-1);
}

signed main() {
    int k, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        build(i, arr[i]);
    }

    while (q--) {
        cin >> k >> a >> b;
        if (k == 1) {
            update(a, b);
        }
        else {
            cout << query(a, b) << '\n';
        }
    }
}