#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1); int mx = 0;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], mx = max(mx, a[i]);
    for (int i = 1; i <= m; i ++ ) cin >> b[i], mx = max(mx, b[i]);

    auto check = [&](int x) -> bool {
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i ++ ) c1 += x >= a[i];
        for (int i = 1; i <= m; i ++ ) c2 += x <= b[i];
        return c1 >= c2;
    };

    auto binary_search = [&](int l, int r) -> int {
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    };

    cout << binary_search(1, mx + 1) << endl;
    return 0;
}