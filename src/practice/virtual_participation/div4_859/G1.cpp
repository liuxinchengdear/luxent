#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp{0, 1, 1};
    for (int i = 3; dp.back() <= 5000; i ++ ) dp.push_back(dp.back() << 1);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        int mx = 0;
        for (int i = 1; i <= n; i ++ ) cin >> a[i], mx = max(mx, a[i]);

        auto binary_search = [&](int l, int r) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (dp[mid] >= mx) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        sort(a.begin(), a.end());
        bool fg = false;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] > dp[i]) {fg = true; break;}
        }
        cout << (fg ? "NO\n" : "YES\n");
    }
    return 0;
}