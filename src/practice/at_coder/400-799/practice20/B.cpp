#include <bits/stdc++.h>
using namespace std;;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<string> g(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> g[i], g[i] = " " + g[i];

    vector<array<int, 2>> dir{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > m;
    };

    string s = "snuke";

    vector<vector<bool>> st(n + 1, vector<bool>(m + 1));
    auto dfs = [&](auto &&dfs, int x, int y, int num) -> bool {
        st[x][y] = true;
        if (x == n && y == m) return true;
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (outline(nx, ny) || st[nx][ny] || g[nx][ny] != s[(num + 1) % 5]) continue;
            if (dfs(dfs, nx, ny, num + 1)) return true;
        }
        return false;
    };

    if (g[1][1] != 's') { cout << "No\n"; exit(0); }
    cout << (dfs(dfs, 1, 1, 0) ? "Yes\n" : "No\n");
    return 0;
}