#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, bool>
#define l first
#define r second

vector<pr> temp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        temp.push_back({a, 0});
        temp.push_back({b, 1});
    }

    sort(temp.begin(), temp.end());
    int sum = 0;
    for (auto i: temp){
        if (i.r)
            sum--;
        
        else
            sum++;

        ans = max(ans, sum);
    }
    
    cout << ans;
}