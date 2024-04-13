#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, arr;

int main(){
    int n, sumA = 0, sumB = 0;
    cin >> n;

    arr.resize(n+1);
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    int l = 1, r = n, t = 1;
    while (l < r && sumA == sumB){
        if (r == l){
            if (sumA + arr[r] == sumB){
                a.push_back(arr[l]);
                sumA += arr[r];
            }
            
            else if (sumB + arr[r] == sumA){
                b.push_back(arr[r]);
                sumB += arr[r];
            }

            else{
                sumA += arr[r];
                break;
            }
        }

        if (t % 2) {
            a.push_back(arr[l]);//1
            a.push_back(arr[r]);//7
            sumA += arr[l]+arr[r];
        }

        else {
            b.push_back(arr[l]);//2
            b.push_back(arr[r]);//
            sumB += arr[l] + arr[r];
        }

        t++;
        l++;
        r--;
    }
    
    if (sumA != sumB)
        cout << "NO SOLUTION";
    
    else{
        cout << a.size() << '\n';
        for (auto i: a)
            cout << i << ' ';

        cout << b.size() << '\n';
        for (auto i: b)
            cout << i << '\n';
    }
}