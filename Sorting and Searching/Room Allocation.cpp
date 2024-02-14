#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define int long long
#define f first
#define s second
#define geti(x, y) get<x>(y)
using namespace std;

// 10         1    2     3      4
// 1 1       1 1  2 3   3  3   3 4
// 2 3       2 3  9 10  
// 2 3       6 7    
// 3 3       8 8
// 3 4       9 9
// 6 7       10 10
// 8 8
// 9 9
// 9 10
// 10 10

vector<tii> v;
vector<int> ans;
priority_queue<pii, vector<pii>, greater<pii>> rooms;

// bool cmp(pii x, pii y){
//     if (x.f == y.f)
//         return x.s < y.s;

//     return x.f < y.f;
// }


signed main(){
    int n;
    cin >> n;

    v.resize(n);
    int i = 0;
    for (auto &[x, y, z]: v){
        cin >> x >> y;
        z = i++;
    }

    sort(v.begin(), v.end());
    ans.resize(n);

    int lr = 0;
    for (int i = 0; i < n; i++){
        if (rooms.empty()){
            lr++;
            rooms.push({geti(1, v[i]), lr});
            ans[geti(2, v[i])] = lr;
        }
        //cout << rooms.top().s << ' ' << rooms.top().f << '\n';
        else {
            pii top = rooms.top();
            //cout << geti(0, v[i]) << ' ' << geti(1, v[i]) << ' ' << top.f << '\n'; 
            if (geti(0, v[i]) > top.f){
                rooms.pop();
                rooms.push({geti(1, v[i]), top.s});
                ans[geti(2, v[i])] = top.s;
            }
            else {
                lr++;
                rooms.push({geti(1, v[i]), lr});
                ans[geti(2, v[i])] = lr;
            }
        }
    }
    
    cout << rooms.size() << '\n';
    for (auto x: ans)
        cout << x << ' ';
}