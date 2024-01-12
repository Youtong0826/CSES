#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

map<int, int> nums;

int main(){
    io;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        nums[i] = 0;

    int t = n-1, a;
    while (t--){
        cin >> a;
        nums[a]++;
    }

    for (auto i: nums)
        if (!i.second)
            cout << i.first;
}