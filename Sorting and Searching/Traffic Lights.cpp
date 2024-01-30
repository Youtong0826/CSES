#include <bits/stdc++.h>
using namespace std;

set<int> lights;
multiset<int> dis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, n, a;
    cin >> x >> n;

    lights.insert(0);
    lights.insert(x);
    dis.insert(x);

    while (n--){
        cin >> a;
        auto r = lights.upper_bound(a);
        auto l = r--;

        //cout << *l << ' ' << *r << '\n';
        dis.erase(dis.lower_bound(*l-*r));
        dis.insert(*l-a);
        dis.insert(a-*r);
        lights.insert(a);

        cout << *dis.rbegin() << '\n';
    }
}