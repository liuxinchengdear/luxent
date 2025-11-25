#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];

    vector<int> work(n + 2);
    for (int i = n; i ; i -- ) {
        work[i] = work[i + 1] + a[i] / b[i];
    }

    bool fg = true;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        if (k > work[i]) { fg = false; break; }
        int t = max(0, k - work[i + 1]);
        res[i] = t; k -= t;
    }
    if (!fg) res = vector<int>(n + 1);
    
    for (int i = 1; i <= n; i ++ ) cout << res[i] << " \n"[i == n];
    return 0;
}