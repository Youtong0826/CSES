#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

int pre[200005];
multiset<int> ms;

signed main(){
    Youtong;
    int n, a, b, ans = INT64_MIN;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }

    for (int i = a; i <= n; i ++){
        if (i > b)
            ms.erase(ms.find(pre[i-b-1]));

        ms.insert(pre[i-a]);
        ans = max(ans, pre[i]-*ms.begin());
    }

    cout << ans;
}