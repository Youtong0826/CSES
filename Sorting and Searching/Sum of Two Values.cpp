#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
map<int, int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++){
        if (ans.count(x-arr[i])){
            cout << ans[x-arr[i]]+1 << ' ' << i+1 << '\n';
            return 0;
        }

        ans[arr[i]] = i;
    }

    cout << "IMPOSSIBLE";
}