#include <bits/stdc++.h>
using namespace std;

multiset<int> nums;
// 1 2
// 1
// 10 10
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a;
        nums.insert(a);
    }

    for (int i = 0; i < m; i++){
        cin >> a;
        auto it = nums.lower_bound(a);

        if ((*it > a && it == nums.begin()) || !nums.size())
            cout << "-1";

        else{
            if (*it > a || it == nums.end())
                it = prev(it, 1);

            cout << *it;
            nums.erase(it);
        }
        cout << '\n';
    }

}