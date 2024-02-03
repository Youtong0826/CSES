#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define vt vector
#define pq priority_queue
#define int long long
#define f first
#define s second
using namespace std;

bool cmp(tii x, tii y){
    return get<2>(x) < get<2>(y);
}

int n;
vector<pii> cus;
vector<int> ans;
queue<tii> rooms; //, vt<tii>, greater<tii>

signed main(){
    fastio;
    int n;
    cin >> n;
    cus.resize(n);
    for (auto &x: cus)
        cin >> x.f >> x.s;

    vector<int> ord(n); 
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [](int x, int y){
        // if (cus[x].f == cus[y].f)
        //     return cus[x].s < cus[y].s;

        if (cus[x].s == cus[y].s)
            return cus[x].f < cus[y].f;

        return cus[x].s < cus[y].s;
    });

    // for (auto i: cus)
    //     cout << i << ' ';
    // cout << '\n';

    rooms.push(make_tuple(cus[ord[0]].s, cus[ord[0]].f, 1));
    ans.resize(n);
    ans[ord[0]] = 1;
    for (int i = 1; i < n; i++){
        auto t = rooms.front();
        cout << get<0>(t) << ' ';
        if (cus[ord[i]].f > get<0>(t)){
            rooms.pop();
            rooms.push(make_tuple(cus[ord[i]].s, cus[ord[i]].f, get<2>(t)));
            cout << get<2>(t) << ' ' << cus[ord[i]].f << ' ' << cus[ord[i]].s;
            ans[ord[i]] = get<2>(t);
        }

        else{
            rooms.push(make_tuple(cus[ord[i]].s, cus[ord[i]].f, rooms.size()+1));
            cout << rooms.size() << ' ' << cus[ord[i]].f << ' ' << cus[ord[i]].s;
            ans[ord[i]] = rooms.size();
        }

        cout << '\n';
    }

    cout << rooms.size() << '\n';
    for (auto i: ans)
        cout << i << ' ';
}