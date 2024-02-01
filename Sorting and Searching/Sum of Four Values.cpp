#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f first
#define s second
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using namespace std;
// declare
int n, x;
vector<int> v;
set<pair<int, pii>> Lsum, Rsum;
//
signed main()
{
    fastio;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Rsum.insert({v[i] + v[j], {i, j}});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            Rsum.erase({v[i] + v[j], {i, j}});
            
        for (int j = 0; j < i; j++)
        {
            int k = x - (v[i] + v[j]);
            pair<int, pii> p = {k, {-1, -1}};
            auto it = Rsum.lower_bound(p);
            if (it == Rsum.end() || it->f != k)
                continue;
            cout << i + 1 << " " << j + 1 << " " << it->s.f + 1 << " " << it->s.s + 1 << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}