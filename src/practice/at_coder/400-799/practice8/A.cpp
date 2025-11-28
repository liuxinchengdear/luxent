#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int n, m, k; cin >> n >> m >> k;

    vector<string> g(n);
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    auto outline = [&](int x, int y) -> bool {
        return x < 0 || x >= n || y < 0 || y >= m;
    };

    vector<vector<bool>> st(n, vector<bool>(m));

    auto check = [&](int x, int y) -> bool {
        if (outline(x, y) || st[x][y] || g[x][y] == '#') return false;
        return true;
    };

    auto dfs = [&](auto &&dfs, int x, int y, int cnt) -> int {
        if (cnt == k) return 1;
        int sum = 0;
        for (int i = 0; i < 4; i ++ ) {
            auto nx = x + dir[i][0], ny = y + dir[i][1];
            if (check(nx, ny)) {
                st[nx][ny] = true;
                sum += dfs(dfs, nx, ny, cnt + 1);
                st[nx][ny] = false;
            }
        }
        return sum;
    };

    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (g[i][j] == '.') { 
                st[i][j] = true;
                res += dfs(dfs, i, j, 0);
                st[i][j] = false;
            }
        }
    }

    cout << res << endl;
    return 0;
}