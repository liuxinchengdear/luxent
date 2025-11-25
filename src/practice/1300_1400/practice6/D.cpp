#include <bits/stdc++.h>
using namespace std;

using tii = tuple<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        vector<tii> a(m);
        for (int i = 0; i < m; i ++ ) {
            int x; cin >> x;
            a[i] = make_tuple(x, x / 100);
        }

        sort(a.begin(), a.end(), [](tii x, tii y) -> bool {
            return get<1>(x) < get<1>(y);
        });

        for (int i = 0; i < n; i ++ ) {
            auto t = i >> 1;
            vector<tii> ans = i & 1 ? vector<tii>{a[m - t - 1], a[t]} : vector<tii>{a[t], a[m - t - 1]};
            for (int j = 0; j < 6; j ++ ) cout << get<0>(ans[j % 2]) << " \n"[j == 5];
        }
    }
    return 0;
}