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

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<vector<Edge>> g(n + 1);
    for (int i = 1; i < n; i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c}); g[b].push_back({a, c});
    }

    auto dfs = [&](auto &&dfs, int u, int fa) -> pii {
        int num = a[u], cost = 0, W = 0;
        for (auto [v, w] : g[u]) {
            if (v == fa) { W = w; continue; }
            auto [nu, ct] = dfs(dfs, v, u);
            num += nu; cost += ct;
        }
        return { num, cost + W * abs(num) };
    };

    auto [num, cost] = dfs(dfs, 1, -1);
    cout << cost << endl;
    return 0;
}