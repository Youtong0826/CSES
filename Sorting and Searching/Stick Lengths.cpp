#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[200005];

signed main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    int mid = arr[n/2], ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(mid-arr[i]);

    cout << ans;
}