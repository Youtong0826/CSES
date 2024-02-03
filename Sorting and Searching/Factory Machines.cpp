#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define vt vector
#define pq priority_queue
#define int int_fast64_t
#define f first
#define s second
using namespace std;

int mh[200005];

signed main(){
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> mh[i];

    int r = 0, l = 1e18, ans= INT_MAX;
    while (r < l){
        int mid = (r+l)/2;

        int cnt = 0, fl = 0;
        for (int i = 0; i < n; i++){
            cnt += mid/mh[i];
            if (cnt >= t){
                ans = min(ans, cnt);
                fl = 1;
                break;
            }
        }

        if (fl)
            l = mid;
        else
            r = mid;
    }
       
    cout << ans;
}