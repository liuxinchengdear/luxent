#include <bits/stdc++.h>
using namespace std;

#define int long long

const double eps = 1e-9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<tuple<int, int, int>> coe;

        for (int i = 0; i < n; i ++ ) {
            int a, b, c; cin >> a >> b >> c;
            coe.push_back(make_tuple(a, b, c));
        }

        auto fun = [&](double x) -> double {
            double val = -1e18;
            for (int i = 0; i < n; i ++ ) {
                auto [a, b, c] = coe[i];
                double tmp = a * x * x + b * x + c;
                val = max(val, tmp);
            }
            return val;
        };

        auto ternary_search = [&](double l, double r) -> double {
            while (r - l > eps) {
                auto m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
                if (fun(m1) <= fun(m2)) r = m2;
                else l = m1;
            }
            return l;
        };

        cout << fixed << setprecision(4) << fun(ternary_search(0, 1000)) << endl;
    }
    return 0;
}