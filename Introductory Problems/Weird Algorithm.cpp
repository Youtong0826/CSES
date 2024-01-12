#include <bits/stdc++.h>
using namespace std;
#define int long long

void f(int n){
    cout << n << ' ';
    if (n == 1)
        return;
    (n % 2)? f(n*3+1): f(n/2);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a;
    cin >> a;
    f(a);
}