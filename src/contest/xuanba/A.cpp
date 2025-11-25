#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; 
    while(cin>> a >> b) {
        a = b = min(a, b);
        cout << a * b << endl;
    }
    return 0;
}