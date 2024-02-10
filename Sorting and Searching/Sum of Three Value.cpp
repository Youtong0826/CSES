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

    for (int i = 0; i < n; i++){
        int l = 0, r = 0;
        while (l < n && r < n){
            
        }
        
    }
        
}