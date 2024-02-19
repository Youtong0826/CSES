#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

vector<pii> v;
multiset<int> p;

signed main(){
    Youtong;
    int n, k, ans = 0;
    cin >> n >> k;
    v.resize(n);
    for (auto &[x, y]: v)
        cin >> y >> x;

    for (int i = 0; i < k; i++)
        p.insert(0);

    // 0 0

    sort(v.begin(), v.end());
    for (auto [x, y]: v){
        auto it = p.upper_bound(y);
        if (it == p.begin())
            continue;
        
        p.erase(--it);
        p.insert(x);
        ans++;
    }

    cout << ans;
}