#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define vt vector
#define int long long
#define Youtong ios_base::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int arr[21];

signed main(){
    Youtong;
    int n, ans = INT64_MAX;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if ((i >> j) & 1)
                sum += arr[j];

            else
                sum -= arr[j];
        }

        ans = min(ans, abs(sum));
    }

    cout << ans;
}