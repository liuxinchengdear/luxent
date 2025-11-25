#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, d; cin >> h >> w >> d;

    vector<string> g(h);
    for (int i = 0; i < h; i ++ ) cin >> g[i];
    
    vector<vector<bool>> st(h, vector<bool>(w));
    queue<int> q; int res = 0;
    for (int i = 0; i < h; i ++ ) {
        for (int j = 0; j < w; j ++ ) {
            if (g[i][j] == 'H') q.push(i * w + j), res ++ , st[i][j] = true;
        }
    }

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x < 0 || x >= h || y < 0 || y >= w;
    };

    auto check = [&](int x, int y) -> bool {
        if (outline(x, y) || g[x][y] == '#' || st[x][y]) return false;
        return true;
    };

    while (q.size() && d -- ) {
        auto size = q.size(); 
        while (size -- ) {
            auto t = q.front(); q.pop();
            int x = t / w, y = t % w;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (check(nx, ny)) q.push(nx * w + ny), res ++ , st[nx][ny] = true;
            }
        }
    }

    cout << res << endl;
    return 0;
}