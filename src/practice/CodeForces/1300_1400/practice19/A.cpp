#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        vector<int> a(n + 1); int mx = -1;
        for (int i = 1; i <= n; i ++ ) cin >> a[i], mx = max(mx, a[i]);

        if (n == 1) { cout << a[1] << endl; continue; }

        k <<= 1;
        for (int i = 1; i <= n; i ++ ) a[i] %= k;

        sort(a.begin() + 1, a.end());

        // for (auto e : a) cout << e << " "; cout << endl;

        auto p = lower_bound(a.begin(), a.end(), k >> 1);

        auto pp = p == a.begin() + 1 ? a.begin() + n : prev(p);

        auto t1 = k - (*p - *pp + k) % k >= k >> 1, t2 = a.back() - a[1] >= k >> 1;

        if (t1 && t2) { cout << "-1\n"; continue; }

        int res = 1e18;
        if (!t1) res = min(res, (*pp - mx % k + k) % k + mx);

        if (!t2) res = min(res, a.back() - mx % k + mx);

        cout << res << endl;
    }
    return 0;
}