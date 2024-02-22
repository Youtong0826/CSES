#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

map<char, int> mp;

signed main(){
    Youtong;
    int c = 0;
    string s, ans = "";
    cin >> s;
    for (auto i: s){
        mp[i]++;
        if (mp[i] % 2 == 0)
            c--;
        
        else
            c++;
    }

    if (c > 1)
        cout << "NO SOLUTION";
    
    else {
        char mid = '!';
        for (auto [x, y]: mp){
            if (y % 2)
                mid = x;

            y /= 2;
            while (y--)
                ans += x;
        }

        string temp = ans;
        reverse(all(temp));

        cout << ans;
        if (mid != '!')
            cout << mid;

        cout << temp;
    }

    return 0;
}