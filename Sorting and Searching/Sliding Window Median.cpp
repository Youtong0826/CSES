#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int n, k;
multiset<int> r, l;
vector<int> v;

void ins(int val){
    if (val < *l.rbegin()){
        l.insert(val);
        if (l.size() > r.size() + 1){
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }
    }
    else{
        r.insert(val);
        if (r.size() > l.size() + 1){
            l.insert(*r.begin());
            r.erase(r.find(*r.begin()));
        }
    }
}

void era(int val){
    if (r.find(val) != r.end())
        r.erase(r.find(val));

    else
        l.erase(l.find(val));

    if (r.empty()){
        r.insert(*l.rbegin());
        l.erase(l.find(*l.rbegin()));
    }

    if (l.empty()){
        l.insert(*r.begin());
        r.erase(r.find(*r.begin()));
    }
}

signed main(){
    Youtong;
    cin >> n >> k;
    v.resize(n);
    for (auto &x: v)
        cin >> x;

    l.insert(v[0]);
    for (int i = 1; i < k; i++)
        ins(v[i]);

    if (l.size() > r.size())
        cout << *l.rbegin();

    else if (l.size() == r.size())
        cout << min(*l.rbegin(), *r.begin());

    else
        cout << *r.begin();

    cout << ' ';

    for (int i = k; i < n; i++){
        if (k == 1){
            ins(v[i]);
            era(v[i-k]);
        }

        else {
            era(v[i-k]);
            ins(v[i]);
        }

        if (l.size() > r.size())
            cout << *l.rbegin();

        else if (l.size() == r.size())
            cout << min(*l.rbegin(), *r.begin());

        else
            cout << *r.begin();

        cout << ' ';
    }
}