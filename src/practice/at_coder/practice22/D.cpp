#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> g[i], g[i] = " " + g[i];

    vector<array<int, 2>> dir{{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

    vector<int> cnt(min(n, m) + 1);

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > m;
    };

    auto count = [&](int x, int y, int d) -> int {
        auto [dx, dy] = dir[d];
        int num = 0, nx = x + dx, ny = y + dy;
        while (!outline(nx, ny) && g[nx][ny] != '.') ++ num, nx += dx, ny += dy;
        return num;
    };

    auto check = [&](int x, int y) -> bool {
        int tmp = -1;
        for (int i = 0; i < 4; i ++ ) {
            if (!i) { tmp = count(x, y, i); continue; }
            if (tmp != count(x, y, i)) return false;
        }
        return true;
    };

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            if (g[i][j] == '#' && check(i, j)) {
                cnt[count(i, j, 0)] ++ ;
            } 
        }
    }

    for (int i = 1; i < cnt.size(); i ++ ) cout << cnt[i] << " \n"[i == cnt.size() - 1];
    return 0;
}