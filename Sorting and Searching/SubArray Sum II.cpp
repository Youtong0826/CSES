#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

map<int, int> cnt;

signed main(){
    fastio;
    int n, k, a;
    cin >> n >> k;

    int psum = 0, ans = 0;
    cnt[0]++;
    while (n--){
        cin >> a;
        psum += a;
        auto it = cnt.lower_bound(psum-k);
        if (it != cnt.end() && it->f == psum-k)
            ans += cnt[psum-k];
        
        cnt[psum]++;
    }

    cout << ans;
}