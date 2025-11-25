#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }

    vector<bool> st(n + 1);

    auto dfs = [&](auto &&dfs, int u) -> pair<int, int> {
        int sum = 0, cnt = 0;
        if (!st[u]) sum ++ , st[u] = true;
        for (auto v : g[u]) {
            cnt ++ ;
            if (!st[v]) {
                auto [n1, n2] = dfs(dfs, v);
                sum += n1; cnt += n2;
            }
        }
        return {sum, cnt};
    };

    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) {
            auto [sum, cnt] = dfs(dfs, i);
            res += 1ll * sum * (sum - 1) / 2 - cnt / 2;
        }
    }
    cout << res << endl;
    return 0;
}