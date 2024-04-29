#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3+5;
int dp[maxn][maxn];

string s1, s2;

int main(){
    cin >> s1 >> s2;

    if (!s1.size() || !s2.size()){
        cout << max(s1.size(), s2.size());
        return 0;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= s1.size(); i++){
        for (int j = 1; j <= s2.size(); j++){
            dp[i][j] = dp[i-1][j-1];
            if (s1[i-1] != s2[j-1])
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }

    cout << dp[s1.size()][s2.size()];
}