#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        vector<string> g(n);
        for (auto &e : g) cin >> e;

        vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        vector<vector<pii>> st(n, vector<pii>(m, {-1, -1}));
        auto dfs = [&](auto &&dfs, int x, int y, int ox, int oy) -> bool {
            if (st[x][y] != make_pair(-1, -1) && st[x][y] != make_pair(ox, oy)) return true;
            st[x][y] = {ox, oy};
            for (int i = 0; i < 4; i ++ ) {
                auto nx = (x + dir[i][0] + n) % n, ny = (y + dir[i][1] + m) % m;
                auto tx = ox + dir[i][0], ty = oy + dir[i][1];
                if (g[nx][ny] == '#' || st[nx][ny] == make_pair(tx, ty)) continue;
                if (dfs(dfs, nx, ny, tx, ty)) return true;
            }
            return false;
        };

        int x, y;
        for (int i = 0; i < n; i ++ ) 
        for (int j = 0; j < m; j ++ )
        if (g[i][j] == 'S') 
        x = i, y = j;

        cout << (dfs(dfs, x, y, x, y) ? "Yes" : "No") << endl;
    }
    return 0;
}