#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i ++ ) {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<pii> poi(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            int x; cin >> x;
            poi[i] = {i, x};
        }
        sort(poi.begin() + 1, poi.end(), [](pii x, pii y) -> bool {
            return x.second < y.second;
        });

        vector<vector<int>> tg(n + 1);

        vector<int> fa(n + 1); iota(fa.begin(), fa.end(), 0);
        auto getfa = [&](auto &&self, int x) -> int {
            return fa[x] == x ? fa[x] : fa[x] = self(self, fa[x]);
        };

        vector<bool> st(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            auto [u, w] = poi[i]; st[u] = true;
            for (auto v : g[u]) {
                if (st[v]) {
                    v = getfa(getfa, v); fa[v] = u;
                    tg[u].push_back(v), tg[v].push_back(u);
                }
            }
        }

        fill(st.begin(), st.end(), false);
        queue<int> q; q.push(poi[n].first); st[poi[n].first] = true;
        vector<int> depth(n + 1); depth[q.front()] = 1;
        while (q.size()) {
            auto size = q.size();
            while (size -- ) {
                auto u = q.front(); q.pop();
                for (auto v : tg[u]) {
                    if (st[v]) continue;
                    q.push(v); st[v] = true;
                    depth[v] = depth[u] + 1;
                }
            }
        }
        for (int i = 1; i <= n; i ++ ) cout << depth[i] << endl;
    }
    return 0;
}