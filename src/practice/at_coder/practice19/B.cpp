#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x; g[i].push_back(x);
    }

    vector<bool> st(n + 1);

    auto dfs = [&](this auto &&dfs, int u, int rt, int len) -> int {
        for (auto v : g[u]) {
            dfs(v, rt, len + 1);
        }
    };
}