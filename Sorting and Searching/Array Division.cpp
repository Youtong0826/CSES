#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int n, k;
vector<int> v;

bool good(int t, int k){
    int sum = 0, sa = 0;

    for (auto x: v){
        if (x > t)
            return 0;

        if (sum + x > t){
            sum = 0;
            sa++;
        }
        sum += x;
    }

    if (sum > 0)
        sa++;

    return sa <= k;
}

signed main(){
    Youtong;
    cin >> n >> k;
    v.resize(n);
    for (auto &x: v)
        cin >> x;
    
    int l = 0, r = INT64_MAX;
    while (l < r){
        int mid = l + (r-l)/2;
        //cout << l << ' ' << r << '\n';
        if (good(mid, k))
            r = mid;
        else
            l = mid+1;
    }
    
    cout << r << '\n';
}