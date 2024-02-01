#include<bits/stdc++.h>
#define int long long
#define pii pair <int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> arr;
stack<int> st;

signed main(){
    int n;
    cin >> n;
    arr.resize(n+1); 
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    

    st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() && arr[st.top()] >= arr[i])
            st.pop();
        
        cout << st.top() << ' ';
        st.push(i);
    }
}
