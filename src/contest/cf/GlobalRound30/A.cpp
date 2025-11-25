#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int mx = -1e9, mn = 1e9;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x;
            mx = max(mx, x); mn = min(mn, x);
        }
        int x; cin >> x;
        cout << (x >= mn && x <= mx ? "YES\n" : "NO\n");
    }
    return 0;
}