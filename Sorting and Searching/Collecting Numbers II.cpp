// 待解

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int arr[maxn], idx[maxn];

void swap(int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    while (m--){
        cin >> x >> y;     
        swap(x, y);
        for (int i = 1; i <= n; i++)
            idx[arr[i]] = i;

        int ans = 1;
        for (int i = 1; i < n; i++)
            if (idx[i] > idx[i+1])
                ans++;

        cout << ans << '\n';
    }
}