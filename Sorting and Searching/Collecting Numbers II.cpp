// 待解
// 以下是參考 Coding-Prep 的做法
#include <bits/stdc++.h>
using namespace std;
int main(){    
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1), idx(n+2);
    idx[0] = 0, idx[n+1] = n+1; // 方便實作
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    int cnt = 1;
    for(int i = 1;i <= n;i++){
        if(idx[i] <= idx[i-1])
            cnt++;
    }

    while(q--){
        int l, r; 
        cin >> l >> r;
        int x = a[l], y = a[r];
        swap(a[l], a[r]); // 判斷交換時候要怎麼改變答案
        if (idx[x-1] <= idx[x] && idx[x-1] > r) cnt++;
        if (idx[x-1] > idx[x] && idx[x-1] <= r) cnt--;
        if (idx[x] <= idx[x+1] && r > idx[x+1]) cnt++;
        if (idx[x] > idx[x+1] && r <= idx[x+1]) cnt--;		
        idx[x] = r;
        if (idx[y-1] <= idx[y] && idx[y-1] > l) cnt++;
        if (idx[y-1] > idx[y] && idx[y-1] <= l) cnt--;
        if (idx[y] <= idx[y+1] && l > idx[y+1]) cnt++;
        if (idx[y] > idx[y+1] && l <= idx[y+1]) cnt--;	
        idx[y] = l;

        cout << cnt << '\n';
    }
}