#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n; int a, b; cin >> a >> b;
        if (a > n || a == n && b) { cout << "No\n"; continue; }

        n -= a; int t = min(a + 1, n), num = t + (n - t >> 1);
        if (n * num < b) { cout << "No\n"; continue; }
        cout << "Yes\n";
    }
    return 0;
}