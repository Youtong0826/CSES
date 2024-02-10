#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define vt vector
#define pq priority_queue
#define int int64_t
#define f first
#define s second
using namespace std;

vt<pii> arr;

signed main(){
    fastio;
    int n;
    cin >> n;

    arr.resize(n);
    for (auto &x: arr)
        cin >> x.f >> x.s;

    sort(arr.begin(), arr.end());
    int now = 0, rew = 0;
    for (auto i: arr){
        now += i.f;
        rew += i.s-now;
    }

    cout << rew;
}