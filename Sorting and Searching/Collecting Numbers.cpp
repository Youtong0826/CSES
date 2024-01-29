#include <bits/stdc++.h>
using namespace std;

int idx[200005];

int main(){
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a;
        idx[a] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (idx[i] < idx[i-1])
            ans++;

    cout << ans;
}