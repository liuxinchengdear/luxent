#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;

        int w; cin >> w;
        vector<int> a(n * m + 1);
        for (int i = 1; i <= w; i ++ ) cin >> a[i];

        sort(a.begin(), a.end());

        vector<vector<int>> g(n + 1, vector<int>(m + 1));

        vector<array<int, 2>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> st(n + 1, vector<bool>(m + 1));

        auto outline = [&](int x, int y) -> bool {
            return x < 1 || x > n || y < 1 || y > m;
        };

        auto dfs = [&](this auto &&dfs, int num, int x, int y, int op) -> void {
            if (num == n * m + 1) return;
            st[x][y] = true; g[x][y] = a[num];
            auto nx = x + dir[op % 4][0], ny = y + dir[op % 4][1];
            if (outline(nx, ny) || st[nx][ny]) nx = x + dir[( ++ op) % 4][0], ny = y + dir[op % 4][1];

            dfs(num + 1, nx, ny, op);
        };

        dfs(1, 1, 1, 0); 

        // for (int i = 1; i <= n; i ++ ) {
        //     for (int j = 1; j <= m; j ++ ) cout << g[i][j] << " \n"[j == m];
        // }

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }

        int res = 0;
        for (int i = k; i <= n; i ++ ) {
            for (int j = k; j <= m; j ++ ) {
                res += g[i][j] - g[i - k][j] - g[i][j - k] + g[i - k][j - k];
            }
        }
        cout << res << endl;
    }
    return 0;
}