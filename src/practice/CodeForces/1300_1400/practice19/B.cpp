#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); int mx = -1, mn = 1e9;
        for (int i = 1; i <= n; i ++ ) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);

        vector<int> res;

        auto eval = [&](int x) -> pair<int, int> {
            int mx = -1, mn = 1e9;
            for (int i = 1; i <= n; i ++ ) {
                a[i] = abs(a[i] - x); mx = max(mx, a[i]); mn = min(mn, a[i]);
            }
            return make_pair(mn, mx);
        };

        auto binary_search = [&](int l, int r) -> void {
            while (l < r || l == r && l) {
                if (res.size() > 40) break;
                int mid = l + r >> 1; res.push_back(mid);
                auto [mn, mx] = eval(mid);
                l = mn, r = mx;
            }
        };

        binary_search(mn, mx);
        if (res.size() > 40) { cout << "-1\n"; continue; }
        cout << res.size() << endl;
        for (auto e : res) cout << e << " "; cout << endl;
    }
    return 0;
}