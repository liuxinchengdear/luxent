#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c; cin >> n >> c; c -- ;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int mn = 1e18, res = 0;
    for (int i = 1; i <= n; i ++ ) {
        mn = min(mn, c * pre[i - 1]);
        res = max(res, pre[i] * c - mn);
    }
    cout << pre[n] + res << endl;
    return 0;
}