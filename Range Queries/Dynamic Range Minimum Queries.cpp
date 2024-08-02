#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+1;

struct Node {
    int l, r;
    int lidx, ridx;
    int val;
} seg[maxn*2];

int sidx = 1, a[maxn];

void build(int l, int r, int idx) {
    seg[idx].l = l, seg[idx].r = r;
    if (l == r-1) {
        seg[idx].val = a[l];
    } 
    else {
        int lidx = seg[idx].lidx = sidx++;
        int ridx = seg[idx].ridx = sidx++;
        int mid = (l+r)/2;
        build(l, mid, lidx);
        build(mid, r, ridx);
        seg[idx].val = min(seg[lidx].val, seg[ridx].val);
    }
}

void update(int x, int v, int idx) {
    if (seg[idx].l == seg[idx].r-1)
        seg[idx].val = v;
    
    else {
        int mid = (seg[idx].l + seg[idx].r)/2;
        if (x < mid) 
            update(x, v, seg[idx].lidx);

        else
            update(x, v, seg[idx].ridx);

        seg[idx].val = min(seg[seg[idx].lidx].val, seg[seg[idx].ridx].val);
    }
}

int query(int l, int r, int idx){
    int mid = (seg[idx].l+seg[idx].r)/2;
    // cout << seg[idx].l << ' ' << seg[idx].r << '\n';
    if (seg[idx].l == l && seg[idx].r == r)
        return seg[idx].val;

    if (r <= mid)
        return query(l, r, seg[idx].lidx);
    
    else if (l >= mid)
        return query(l, r, seg[idx].ridx);
    
    else {
        return min(query(l, mid, seg[idx].lidx), query(mid, r, seg[idx].ridx));
    }
}

int main(){
    int n, q, o, x, y;

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, n, 0);

    while (q--){
        cin >> o >> x >> y;
        if (o == 1) {
            update(x-1, y, 0);
        }
        else {
            cout << query(x-1, y, 0) << '\n';
        }
    }
    
}