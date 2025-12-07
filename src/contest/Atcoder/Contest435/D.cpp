#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> g(n + 1), G(n + 1);
    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); G[b].push_back(a);
    }

    vector<bool> st(n + 1);

    auto dfs = [&](auto &&dfs, int u) -> void {
        if (st[u]) return; 
        st[u] = true;

        for (auto v : G[u]) {
            dfs(dfs, v);
        }
    };

    int q; cin >> q;
    while (q -- ) {
        int op, u; cin >> op >> u;
        if (op == 1) dfs(dfs, u);
        else cout << (st[u] ? "Yes\n" : "No\n");
    }

    return 0;
}