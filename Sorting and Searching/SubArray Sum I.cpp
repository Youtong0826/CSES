#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

set<int> cnt({0});

signed main(){
    fastio;
    int n, k, a;
    cin >> n >> k;

    int psum = 0, ans = 0;
    while (n--){
        cin >> a;
        psum += a;
        auto it = cnt.lower_bound(psum-k);
        if (it != cnt.end() && *it == psum-k)
            ans++;
        
        cnt.insert(psum);
    }

    cout << ans;
}