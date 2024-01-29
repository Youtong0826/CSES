#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> nums;

int main(){
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        nums.push_back({b, a});
    }

    sort(nums.begin(), nums.end());
    int endline = nums[0].first, ans = 1;
    for (int i = 1; i < n; i++){
        if (nums[i].second >= endline){
            ans++;
            endline = nums[i].first;
        }
    }
    
    cout << ans;
}