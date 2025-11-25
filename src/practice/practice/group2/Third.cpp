#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

#define double long double

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; double l, r; cin >> n >> l >> r;

    vector<double> coe(n + 1);
    for (int i = n; i >= 0; i -- ) cin >> coe[i];

    auto fun = [&](double x) -> double {
        double ans = 0, tmp = 1;
        for (int i = 0; i <= n; i ++ ) {
            ans = ans + tmp * coe[i]; tmp = tmp * x;
        }
        return ans;
    };

    auto ternary_search = [&](double l, double r) -> double {
        while (r - l > eps) {
            double m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;;
            if (fun(m1) > fun(m2)) r = m2;
            else l = m1;
        }
        return l;
    };

    cout << fixed << setprecision(9) << ternary_search(l, r) << endl;
    return 0;
}