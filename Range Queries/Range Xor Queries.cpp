#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5+1;
int a[maxn];
// struct node {
//     int l, r, val;
// } seg[maxn*2];
// void build(int l, int r, int idx) {
//     seg[idx].l = l;
//     seg[idx].r = r;
//     if (l == r) 
//         seg[idx].val = a[l];
 
//     else {
//         int mid = (l+r) >> 1;
//         build(l, mid, (1 << idx));
//         build(mid+1, r, (1 << idx)+1);
//         seg[idx].val = seg[(1 << idx)].val ^ seg[(1 << idx)+1].val;
//     }
 
//     // cout << l << ' ' << r << ' ' << seg[idx].val << '\n';
// }
 
// int query(int l, int r, int idx) {
//     // cout << l << ' ' << r << ' ' << seg[idx].l << ' ' << seg[idx].r << ' ' << seg[idx].val << '\n';
//     if (seg[idx].l == l && seg[idx].r == r) 
//         return seg[idx].val;
 
//     int mid = (seg[idx].l+seg[idx].r) >> 1;
//     if (r <= mid) {
//         return query(l, r, (1 << idx));
//     }
 
//     else if (l > mid) {
//         return query(l, r, (1 << idx)+1);
//     }
 
//     else {
//         return query(l, mid,  (1 << idx)) ^ query(mid+1, r,  (1 << idx)+1);
//     }
// }
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x, y;
    cin >> n >> q;
    cin >> a[1];
    for (int i = 2; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i-1];
    }
 
    while (q--) {
        cin >> x >> y;
        cout << (a[y] ^ a[x-1]) << '\n';
    }    
}
