#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int n, k, lsum = 0, rsum = 0;
multiset<int> r, l;
vector<int> v;

void check_set(){
    for (auto x: r)
        cout << x << ' ';
 
    cout << '\n';
    for (auto x: l)
        cout << x << ' ';
    
    cout << "\n\n";
}

void ins(int val){
    if (val < *l.rbegin()){
        l.insert(val);
        lsum += val;
        if (l.size() > r.size() + 1){
            rsum += *l.rbegin();
            r.insert(*l.rbegin());
            lsum -= *l.rbegin();
            l.erase(l.find(*l.rbegin()));
        }
    }
    else{
        r.insert(val);
        rsum += val;
        if (r.size() > l.size() + 1){
            lsum += *r.begin();
            l.insert(*r.begin());
            rsum -= *r.begin();
            r.erase(r.find(*r.begin()));
        }
    }
}

void era(int val){
    if (r.find(val) != r.end()){
        rsum -= val;
        r.erase(r.find(val));
    }

    else{
        lsum -= val;
        l.erase(l.find(val));
    }

    if (r.empty()){
        rsum += *l.rbegin();
        r.insert(*l.rbegin());
        lsum -= *l.rbegin();
        l.erase(l.find(*l.rbegin()));
    }

    if (l.empty()){
        lsum += *r.begin();
        l.insert(*r.begin());
        rsum -= *r.begin();
        r.erase(r.find(*r.begin()));
    }
}

//2
//3 4
//

int calc(){
    int t = *l.rbegin();
    if (l.size() == r.size())
        t = min(*l.rbegin(), *r.begin());
    
    else if (l.size() < r.size())
        t = *r.begin();
    
    return (t*l.size()-lsum)+(rsum - t*r.size());
}

signed main(){
    Youtong;
    cin >> n >> k;
    v.resize(n);
    for (auto &x: v)
        cin >> x;

    l.insert(v[0]);
    lsum += v[0];
    for (int i = 1; i < k; i++)
        ins(v[i]);

    cout << calc() << ' ';
    // cout << rsum << ' ' << lsum << '\n';
    // check_set();

    for (int i = k; i < n; i++){
        if (k == 1){
            ins(v[i]);
            era(v[i-k]);
        }

        else {
            era(v[i-k]);
            ins(v[i]);
        }

        cout << calc() << ' ';
        // cout << rsum << ' ' << lsum << '\n';
        // check_set();
    }
}