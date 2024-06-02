#include <bits/stdc++.h>
#define pb(x) emplace_back(x)
#define sz(x) ((int) x.size())
using namespace std;

vector<int> a, b, arr;

int main(){
    int n;
    cin >> n;
    
    if (n < 3){
        cout << "NO" << '\n';
        return 0;
    }
    
    if (n == 3) {
        cout << "YES\n";
        cout << "2\n1 2\n";
        cout << "1\n3\n";
        return 0;
    }

    bool f1 = n % 4 == 3, f2 = n % 4 == 0;

    if (f1 || f2){
        int k;
        if (f1) {
            a.pb(1);
            a.pb(2);
            b.pb(3);
            k = 4;
        }
        
        if (f2) {
            k = 1;
        }

        for (int i = k; i <= n; i++){
            (i % 4 == 0 + (k == 1) || i % 4 == (3 + (k == 1)) % 4)? a.pb(i): b.pb(i);
        }

        cout << "YES\n" << sz(a) << '\n';
        for (auto e: a)
            cout << e << ' ';

        cout << '\n' << sz(b) << '\n';
        for (auto e: b)
            cout << e << ' ';

        return 0;
    }

    cout << "NO";
}