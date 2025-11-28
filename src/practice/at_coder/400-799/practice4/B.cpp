#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i ++ ) cin >> g[i];
    
    queue<int> q;
    vector<vector<bool>> st(n, vector<bool>(m));
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (g[i][j] == 'E') q.push(i * m + j), st[i][j] = true;
        }
    }

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x >= n || x < 0 || y >= m || y < 0;
    };

    auto check = [&](int x, int y) -> bool {
        if (outline(x, y) || g[x][y] == '#') return false;
        return true;
    };

    string op = "v><^";

    while (q.size()) {
        auto size = q.size(); 
        while (size -- ) {
            auto t = q.front(); q.pop();
            int x = t / m, y = t % m;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (!check(nx, ny) || st[nx][ny]) continue;
                g[nx][ny] = op[i]; st[nx][ny] = true; q.push(nx * m + ny);
            }
        }
    }

    for (int i = 0; i < n; i ++ ) cout << g[i] << endl;
    return 0;
}