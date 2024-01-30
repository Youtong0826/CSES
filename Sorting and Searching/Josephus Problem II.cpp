#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree <int, 
    null_type, 
    less<int>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> order_set;
int n, k;

signed main(){
    fastio;
    cin >> n >> k;
    int idx = k % n;
    for(int i = 1 ;i <= n; i++) 
        order_set.insert(i);

    while (--n){
        int cur = *order_set.find_by_order(idx);
        cout << cur << " ";
        order_set.erase(cur);
        idx = (idx + k) % n;
    }
    cout << *order_set.begin() << "\n";
    return 0;
}