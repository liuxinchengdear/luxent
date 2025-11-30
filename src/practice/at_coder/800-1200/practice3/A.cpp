#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, w;
};

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<Edge>> g(n + 1);

    for (int i = 0; i < m; i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    vector<bitset<1025>> st(n + 1);

    queue<pii> q; q.push({1, 0});
    while (q.size()) {
        auto [u, fg] = q.front(); q.pop();
        for (auto [v, w] : g[u]) {
            auto t = w ^ fg;
            if (!st[v][t]) {
                st[v][t] = 1;
                q.push({v, t});
            }
        }
    }

    for (int i = 0; i < 1025; i ++ ) if (st[n][i]) return cout << i << endl, 0;
    return cout << -1 << endl, 0;
}