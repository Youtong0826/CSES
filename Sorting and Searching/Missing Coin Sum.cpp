#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[200005];
// 2 9 1 2 7
// 1 2 2 7 9
//
signed main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]-sum > 1)
            break;

        sum += arr[i];
    }

    cout << sum+1;
}