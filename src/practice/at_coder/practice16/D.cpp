#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, m, l, r; cin >> a >> m >> l >> r;

    bool fg = false;
    if (abs(a - l) % m == 0 || abs(a - r) % m == 0) fg = true;

    if (fg) cout << (1 + (r - l) / m) << endl;
    else {
        int t = abs(a - l) / m, p;
        if (a < l) p = a + (t + 1) * m;
        else p = a - t * m; 
        if (p > r) { cout << "0\n"; exit(0); }
        cout << (1 + (r - p) / m) << endl;
    }
    return 0;
}