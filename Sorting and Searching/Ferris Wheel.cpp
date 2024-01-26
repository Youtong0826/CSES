#include <bits/stdc++.h>
using namespace std;

int p[200005];

// 雙指針
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p+n);
    int l = 0, r = n-1, ans = 0;
    while (l <= r){
        if (p[l] + p[r] > x)
            r--;
        else{
            l++;
            r--;
        }
        ans++;
    }
    
    cout << ans;
}