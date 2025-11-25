#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        using pii = pair<int, int>;

        int n, m; cin >> n >> m;
        vector<pii> a(n);
        int c0 = 0, c1 = 0;
        int sum = 0, sum1 = 0, sum0 = 0;
        for (int i = 0; i < n; i ++ ) {
            int x, y; cin >> x >> y;
            a[i] = {x, y}; sum += max(x, y);
            x > y ? c1 ++ , sum1 += x: c0 ++ , sum0 += y;
        }

        if (n == 1) {cout << sum << '\n'; continue;}

        if (m >= 2 * c0 + c1) {
            if (c1 <= 1) cout << sum0 << '\n';
            else cout << sum << '\n';
        }
        else {
            vector<pii> tt;

            tt.push_back({-1, -1});

            int tmp = 0;
            for (int i = 0; i < n; i ++ ) {
                auto [x, y] = a[i];
                if (x > y) tmp += x;
                else tt.push_back({x, y});
            }
            sort(tt.begin() + 1, tt.end(), [](pii x, pii y) {
                return x.first > y.first || x.first == y.first && x.second < y.second;
            });

            vector<int> pre_1(c0 + 1), pre_0(c0 + 1);
            for (int i = 1; i <= c0; i ++ ) {
                pre_1[i] = pre_1[i - 1] + tt[i].first, pre_0[i] = pre_0[i - 1] + tt[i].second;
            }

            int res = tmp + pre_1[c0];
            for (int i = 0; i <= c0; i ++ ) {
                if (c1 + i + 2 * (c0 - i) > m) continue;
                res = max(res, tmp + pre_1[i] + pre_0[c0] - pre_0[i]);
            }
            cout << res << '\n';
        }
    }
    return 0;
}