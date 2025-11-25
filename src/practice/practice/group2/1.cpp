#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x = 1.4000000234;
    cout << x << endl;
    exit(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> x(n), t(n);

        int mn = 1e9, mx = 0;
        for (int i = 0; i < n; i ++ ) cin >> x[i], mn = min(mn, x[i]), mx = max(mx, x[i]);
        for (int i = 0; i < n; i ++ ) cin >> t[i];

        auto fun = [&](double num) -> double {
            double ans = 0;
            for (int i = 0; i < n; i ++ ) ans = max(ans, abs(num - x[i]) + t[i]);
            return ans;
        };

        auto ternary_search = [&](double l, double r) -> double {
            while (r - l > eps) {
                auto m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
                if (fun(m1) < fun(m2)) r = m2;
                else l = m1;
            }
            return l;
        };

        auto nt = ternary_search(mn, mx); cout << nt << endl;
    }
    return 0;
}