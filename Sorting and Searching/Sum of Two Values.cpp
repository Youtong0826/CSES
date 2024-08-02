// #include <bits/stdc++.h>
// using namespace std;

// map<int, int> mp;

// int main(){
//     int n, x, a;
//     cin >> n >> x;


//     for (int i = 1; i <= n; i++){
//         cin >> a;
//         if (mp.count(x-a)){
//             cout << mp[x-a] << ' ' << i << '\n';
//             return 0;
//         }

//         mp[a] = i;
//     }

//     cout << "IMPOSSIBLE";
// }

// #include <bits/stdc++.h>
// #define f first 
// #define s second
// using namespace std;

// set<pair<int, int>> st;

// int main() {
//     int n, x, a;
//     cin >> n >> x;

//     for (int i = 1; i <= n; i++) {
//         cin >> a;
//         auto it = st.lower_bound({x-a, -1});
//         if (it != st.end() && it->f == x-a) {
//             cout << it->s << ' ' << i << '\n';
//             return 0;
//         }

//         st.insert({a, i});
//     }

//     cout << "IMPOSSIBLE";
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    
}