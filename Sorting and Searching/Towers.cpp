#include <bits/stdc++.h>
using namespace std;

int arr[200005];
multiset<int> tower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        auto it = tower.upper_bound(a);
        if (it != tower.end())
            tower.erase(it);

        tower.insert(a);
    }
    
    cout << tower.size();
}