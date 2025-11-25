#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c; cin >> a >> b >> c;
        if (a - b == c) {cout << "-\n"; continue;}
        cout << "+\n"; 
    }
    return 0;
}