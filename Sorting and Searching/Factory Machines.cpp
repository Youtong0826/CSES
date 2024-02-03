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

int mh[200005];

signed main(){
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> mh[i];

    int l = 0, r = INT64_MAX, ans = INT64_MAX;
    while (r - l != 1){
        int mid = (r+l)/2;
        //cout << l << ' ' << r << ' ' << mid << '\n';

        int cnt = 0, fl = 0;
        for (int i = 0; i < n; i++){
            cnt += mid/mh[i];
            if (cnt >= t){
                ans = min(ans, mid);
                fl = 1;
                break;
            }
        }

        if (fl)
            r = mid;
        else
            l = mid;
    }
       
    cout << ans;
}