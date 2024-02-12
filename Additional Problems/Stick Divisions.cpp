#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define vt vector
#define pq priority_queue
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

pq<int, vt<int>, greater<int>> nums;

signed main(){
    Youtong;
    int n, q, a, b, ans = 0;
    cin >> n >> q;
    for (int i = 0; i < q; i++){
        cin >> a;
        nums.push(a);
    }

    for (int i = 1; i < q; i++){
        a = nums.top();
        nums.pop();
        b = nums.top();
        nums.pop();
        nums.push(a+b);
        ans += a+b;
    }
    
    cout << ans;
}