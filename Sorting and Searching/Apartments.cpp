#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int a[maxn], b[maxn];

// 雙指針
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i< m; i++){
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    int p1 = 0, p2 = 0, ans = 0;

    while (p1 < n && p2 < m){
        if (abs(a[p1]-b[p2]) <= k){
            // cout << b[p2] << ' ' << a[p1] << '\n';
            p1++;
            p2++;
            ans++;
        }
        else{
            if (a[p1] < b[p2])
                p1++;
            else
                p2++;
        }
    }
    
    cout << ans;
}