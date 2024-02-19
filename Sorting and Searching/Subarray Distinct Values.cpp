#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

vector<int> v;

signed main(){
    Youtong;
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for (auto &x: v)
        cin >> x;

    int r = 0, l = 0, dis = 0, ans = 0;
    map<int, int> mp;
    while (l < n){
        while (r < n){
            if (!mp.count(v[r]) && dis == k)
                break;

            if (!mp.count(r)){
                mp[v[r]] = 1;
                dis++;
            }
            else
                mp[v[r]]++;

            r++;
        }

        ans += (r - l);
        if (mp[v[l]] == 1){
            dis--;
            mp.erase(v[l]);
        }

        else
            mp[v[l]] -= 1;

        l++;
    }
    
    cout << ans;
}