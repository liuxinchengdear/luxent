#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i < n; i ++ ) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }

    auto dfs = [&](auto &&dfs, int u, int fa) -> int {
        int sum = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            sum += dfs(dfs, v, u);
        }
        return sum;
    };

    auto res = dfs(dfs, 1, -1);

    int t = 0;
    for (auto v : g[1]) {
        t = max(t, dfs(dfs, v, 1));
    }

    cout << res - t << endl;
    return 0;
}