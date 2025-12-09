#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pii> a(n + 1);

    vector<set<pii, greater<pii>>> g(m + 1);

    vector<int> t(n + 1);

    for (int i = 0; i < n; i ++ ) {
        int x, y; cin >> x >> y;
        a[i] = {x, y}; g[y].insert({x, i + 1});
    }

    for (auto E : g) {
        int num = 0;
        for (auto [h, id] : E) t[id] = 1e9 - h - ++ num;
    }

    int q; cin >> q;
    while (q -- ) {
        int t, id; cin >> t >> id;
    }
}