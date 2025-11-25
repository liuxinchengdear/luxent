#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // |a + b| + |a - b| = 2 * max(|a|, |b|);

    int t; cin >> t; while (t -- ) {
        int a, b, c, d, e, f, g, h; cin >> a >> b >> c >> d >> e >> f >> g >> h;
        cout << max(abs(a + c - e - g), abs(b + d - f - h)) << '\n';
    }
    return 0;
}