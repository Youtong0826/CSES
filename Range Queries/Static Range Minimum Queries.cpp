#include <bits/stdc++.h>
using namespace std;

// 稀疏表
// dp[i][j] = [i, i+2^j-1] 的最小值
//          = min([i, i+2^(j-1)-1], [i+2^(j-1)-1, i+2^j-1]) 
//          = min(dp[i][j-1], dp[i+2^(j-1)][j-1])

struct sparse_table {
	int _n, _len;
	vector<vector<int>> st;

    sparse_table(vector<int> &vt): _n(vt.size()) {
        _len = ceil(__lg(_n)) + 1;
        st.assign(_n, vector<int>(_len, INT_MAX));

        for (int i = 0; i < _n; i++) {
            st[i][0] = vt[i];
        }

        for (int j = 1; j < _len; j++) {
            for (int i = 0; i + (1 << (j - 1)) < _n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int m = floor(__lg(r - l + 1));
        return min(st[l][m], st[r - (1 << m) + 1][m]);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> vt(n);
    for (int i = 0; i < n; i++)
        cin >> vt[i];

    sparse_table sp(vt);

    int x, y;
    while (q--) {
        cin >> x >> y;
        cout << sp.query(x-1, y-1) << '\n';
    }
}