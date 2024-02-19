#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

map<int, int> mp;

signed main(){
    Youtong;
    int n, a, psum = 0, ans = 0;
    cin >> n;
    
    mp[0] = 1;
    for (int i = 0; i < n; i++){
        cin >> a;
        psum += a;
        auto it = mp.lower_bound((psum % n + n) % n);
        //cout << it->f << '\n';
        if (it != mp.end() && it->f == (psum % n + n) % n)
            ans += it->s;

        mp[(psum % n + n) % n]++;
    }

    cout << ans;
}