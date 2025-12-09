#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    vector<int> d(1 << n);

    for (int i = 0; i < 1 << n; ++ i) {
        int cnt = 0;
        for (int j = 0, num = 0; j < n; ++ j) {
            if (i >> j & 1) {
                num += a[j];
                if (num == c) cnt ++ , num = 0;
            }
        }
        d[i] = cnt;
    }

    int res = 0;
    for (int i = 1; i < 1 << n; ++ i) {
        res = max(res, d[i] + d[(1 << n) - i]);
    }
    cout << res << endl;
    return 0;
}