#include <bits/stdc++.h>
using namespace std;
 
set<int> nums;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        nums.insert(a);
    }
 
    cout << nums.size();
}