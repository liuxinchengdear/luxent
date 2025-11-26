#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        if (n == 2) { cout << "1 1\n"; continue; }
        if (n & 1) { cout << "-1\n"; continue; }

        n /= 2;
        for (int i = 1; i <= n; i ++ ) cout << i << " " << i << " ";
    }
    return 0;
}