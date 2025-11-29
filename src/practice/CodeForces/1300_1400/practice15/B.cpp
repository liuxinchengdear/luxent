#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, b, c; cin >> n >> b >> c;

        if (!b) {
            if (n - c > 2) { cout << "-1\n"; continue; }
            cout << (c >= n ? n : n - 1) << '\n'; continue;
        }

        if (c >= n) { cout << n << '\n'; continue; }

        int cnt = (n - 1 - c) / b + 1; cout << n - cnt << endl;
    }
    return 0;
}