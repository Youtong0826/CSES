#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;

int nums[200005];

signed main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int last = nums[0], times = 0;
    for (int i = 1; i < n; i++){
        if (nums[i] < last){
            int temp = last - nums[i];
            times += temp;
            nums[i] += temp;
        }
        last = nums[i];
    }

    cout << times;
}