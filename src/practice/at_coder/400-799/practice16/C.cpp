#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));

    vector<array<int, 2>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > n;
    };

    auto check = [&](int x, int y) -> bool {
        return !outline(x, y) && !g[x][y];
    };

    auto dfs = [&](auto &&dfs, int num, int x, int y, int d) -> void {
        if (num == n * n) return;
        g[x][y] = num;
        int nx = x + dir[d % 4][0], ny = y + dir[d % 4][1];
        if (!check(nx, ny)) {
            d ++ ;
            nx = x + dir[d % 4][0], ny = y + dir[d % 4][1];
        }
        dfs(dfs, num + 1, nx, ny, d);
    };

    dfs(dfs, 1, 1, 1, 0);

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (!g[i][j]) { cout << "T "; continue; }
            cout << g[i][j] << " \n"[j == n];
        }
    }
    return 0;
}