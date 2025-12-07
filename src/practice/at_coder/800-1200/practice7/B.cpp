#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> s(n + 1);

    for (int i = 1; i <= n; i ++ ) cin >> s[i], s[i] = " " + s[i];

    int a, b, c, d; cin >> a >> b >> c >> d;

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > m;
    };

    auto BFS = [&](int sx, int sy, int ex, int ey) -> int {
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));
        vector<vector<bool>> st(n + 1, vector<bool>(m + 1));
        dist[sx][sy] = 0;
        deque<pii> dq; dq.push_back({sx, sy});

        while (dq.size()) {
            auto [x, y] = dq.front(); dq.pop_front();
            if (st[x][y]) continue; st[x][y] = true;

            for (int i = 0; i < 4; ++ i) {
                auto nx = x + dir[i][0], ny = y + dir[i][1];

                if (outline(nx, ny) || s[nx][ny] == '#') continue;
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y]; 
                    dq.push_front({nx, ny});
                }
            }

            for (int i = 0; i < 4; ++ i) {
                for (int j = 1; j <= 2; ++ j) {
                    auto nx = x + dir[i][0] * j, ny = y + dir[i][1] * j;
                    if (outline(nx, ny)) continue;
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[ex][ey];
    };

    cout << BFS(a, b, c, d) << endl;
    return 0;
}