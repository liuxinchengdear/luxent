#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<pii> b(m);
    for (int i = 0; i < m; i ++ ) {
        int x; cin >> x;
        b[i] = {i + 1, x};
    }

    sort(b.begin(), b.end(), [](pii x, pii y) -> bool {
        return x.second < y.second;
    });

    vector<int> res(m + 1, -1);
    for (int i = 1; i <= n && b.size(); i ++ ) {
        while (b.size() && b.back().second >= a[i]) res[b.back().first] = i, b.pop_back();
    }

    for (int i = 1; i <= m; i ++ ) cout << res[i] << '\n';
    return 0;
}
