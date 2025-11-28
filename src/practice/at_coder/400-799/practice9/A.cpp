#include <bits/stdc++.h>
using namespace std;

#define int long long

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
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, -w});
    }

    vector<int> a(n + 1); vector<bool> st(n + 1);


    auto dfs = [&](auto &&dfs, int u, int fa) ->void {
        st[u] = true;
        for (auto [v, w] : g[u]) {
            if (v == fa || st[v]) continue;
            a[v] = a[u] + w; dfs(dfs, v, u);
        }
    };

    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) dfs(dfs, i, -1);
    }

    for (int i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
    return 0;
}