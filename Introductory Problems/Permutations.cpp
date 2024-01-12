#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    io;
    int n;
    cin >> n;
    if (n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i = 2; i <= n; i+=2)
        cout << i << ' ';

    for (int i = 1; i <= n; i+=2)
        cout << i << ' ';
}