#include <bits/stdc++.h>
using namespace std;

map<int, int> nums;
int arr[200005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, l = 0, r = 0, ans = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (r < n){
        while (!nums[arr[r]] && r < n){
            nums[arr[r]]++;
            r++;
        }

        ans = max(ans, r-l);
        nums[arr[l]]--;
        l++;
    }
    
    cout << ans;
}