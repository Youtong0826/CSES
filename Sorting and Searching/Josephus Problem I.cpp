#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int n;
list<int> lst;
vector<list<int>::iterator> era;

signed main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        lst.push_back(i);

    while(lst.size() > 1){
        era.clear();
        auto it = next(lst.begin());
        int sz = lst.size();

        for (int i = 2; i <= sz; i += 2, advance(it, 2)){
            era.push_back(it);
            cout << *it << " ";
        }

        for (int i = 0; i < era.size(); i++)
            lst.erase(era[i]);
        

        if (sz % 2 == 1){
            lst.push_front(*prev(lst.end()));
            lst.erase(prev(lst.end()));
        }
    }

    cout << *lst.begin()<<"\n";
    return 0;
}