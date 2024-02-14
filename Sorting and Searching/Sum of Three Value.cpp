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

vt<pii> nums;

signed main(){
    int n, x;
    cin >> n >> x;

    nums.resize(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].f;
        nums[i].s = i+1;
    }


    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        int t = x-nums[i].f, l = 0, r = n-1;
        while (l != r){
            if (l != i && r != i && nums[l].f + nums[r].f == t){
                cout << nums[i].s << ' ' << nums[l].s << ' ' << nums[r].s << '\n';
                return 0;
            }

            if (nums[l].f + nums[r].f < t)
                l++;
            else
                r--;
        }
    }
        
    cout << "IMPOSSIBLE";
}