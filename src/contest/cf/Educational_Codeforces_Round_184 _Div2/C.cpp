#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i];

        int res = 0; int mn = 1e18;
        for (int r = 1; r <= n; r ++ ) {
            mn = min(mn, r * r - r - pre[r - 1]);
            res = max(res, r * r + r - pre[r] - mn);
        }
        cout << res + pre[n] << endl;
    }
    return 0;
}