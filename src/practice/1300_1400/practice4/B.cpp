#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        vector<pii> lin(n);
        for (int i = 1; i <= n; i ++ ) {
            int l = min(a[i], b[i]), r = max(a[i], b[i]);
            lin[i - 1] = {l, r};
        }
        sort(lin.begin(), lin.end());
        auto [st, ed] = lin.front();
        bool fg = false; int ans = 0, mn = 1e9;
        ans += ed - st;
        for (int i = 1; i < n; i ++ ) {
            auto [l, r] = lin[i];
            if (l <= ed) fg = true, ed = max(r, ed);
            else mn = min(mn, l - ed), st = l, ed = r;
            ans += r - l;
        }
        if (fg) cout << ans << endl;
        else cout << ans + 2 * mn << endl;
    }
    return 0;
}