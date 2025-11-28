#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < m; i ++ ) {
            int a, b; cin >> a >> b;
            g[a].push_back(b); g[b].push_back(a);
        }

        for (int i = 1; i <= n; i ++ ) sort(g[i].begin(), g[i].end());

        vector<bool> st(n + 1), nt(n + 1, true);
        vector<int> res;
        auto dfs = [&](auto &&dfs, int u) -> bool {
            if (!nt[u]) return false;
            
            st[u] = true; res.push_back(u);
            if (u == y) { for (auto e : res) cout << e << " "; cout << endl; return true; }
            
            for (auto v : g[u]) {
                if (st[v]) continue;
                if (dfs(dfs, v)) return true;
            }

            st[u] = false; res.pop_back(); 
            return nt[u] = false;
        };

        dfs(dfs, x);
    }

    return 0;
}