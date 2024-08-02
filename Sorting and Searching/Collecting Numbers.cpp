// #include <bits/stdc++.h>
// using namespace std;

// int idx[200005];

// int main(){
//     int n, a;
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         cin >> a;
//         idx[a] = i;
//     }

//     int ans = 1;
//     for (int i = 2; i <= n; i++)
//         if (idx[i] < idx[i-1])
//             ans++;

//     cout << ans;
// }

#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main(){
    int n, ans = 1, x;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; ++i){ 
        if (arr[i] < arr[i - 1]){
            ans++;
        }
    }
    
    cout << ans;
}