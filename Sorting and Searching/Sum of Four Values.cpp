#include <bits/stdc++.h>
#define int long long
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, x;
vector<pii> v;
vector<tii> cnt;
set<tii> st;

signed main(){
    fastio;
    cin >> n >> x;

    v.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> v[i].f;
        v[i].s = i;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                st.insert(make_tuple(v[i].f + v[j].f, i, j));
                cnt.push_back(make_tuple(v[i].f + v[j].f, i, j));
            }
        }
    }

    for (auto i: cnt){
        int t = x - get<0>(i);
        auto it = st.lower_bound(make_tuple(t, -1, -1));
        if (it != st.end() && get<0>(*it) == t && get<1>(*it) != get<1>(i) && get<2>(*it) != get<2>(i) && get<1>(i) != get<2>(*it) && get<2>(i) != get<1>(*it)){
            cout << get<1>(i) << ' ' << get<2>(i) << ' ' << get<1>(*it) << ' ' << get<2>(*it) << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}