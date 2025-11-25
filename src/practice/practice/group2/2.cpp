#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(1 << n, vector<int>(1 << n));

    auto dfs = [&](auto &&dfs, int x, int y, int r) -> void {
        if (r == 0) { g[x][y] = 1; return; }
        int x1 = x, y1 = y + (1 << r - 1);
        int x2 = x + (1 << r - 1), y2 = y;
        int x3 = x + (1 << r - 1), y3 = y + (1 << r - 1);
        dfs(dfs, x1, y1, r - 1);
        dfs(dfs, x2, y2, r - 1);
        dfs(dfs, x3, y3, r - 1);
    };

    dfs(dfs, 0, 0, n);

    for (auto E : g) { for (auto e : E) cout << e << " "; cout << endl; }
    return 0;
}