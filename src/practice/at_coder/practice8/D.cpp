#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

using tpp = tuple<pii, pii>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s, t; cin >> n >> s >> t;

    vector<tpp> tmp(n);
    for (int i = 0; i < n; i ++ ) {
        pii l, r; int a, b, c, d; cin >> a >> b >> c >> d;
        l = {a, b}; r = {c, d};
        tmp[i] = {l, r};
    }

    double res = 1e18;
    auto dfs = [&](auto &&dfs, int de, int lx, int ly, double ans, int st) -> void {
        if (de == n) { res = min(res, ans); return; }
        for (int i = 0; i < n; i ++ ) {
            if (st >> i & 1) continue;
            auto [a, b] = get<0>(tmp[i]); auto [c, d] = get<1>(tmp[i]);
            double len = sqrt(pow(a - c, 2) + pow(b - d, 2));
            double d1 = sqrt(pow(a - lx, 2) + pow(b - ly, 2));
            double d2 = sqrt(pow(c - lx, 2) + pow(d - ly, 2));
            dfs(dfs, de + 1, c, d, d1 / s + len / t + ans, st + (1 << i));
            dfs(dfs, de + 1, a, b, d2 / s + len / t + ans, st + (1 << i));
        }
    };

    dfs(dfs, 0, 0, 0, 0, 0);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}