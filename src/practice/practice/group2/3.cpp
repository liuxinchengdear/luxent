#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> g(10);
    for (auto &e : g) cin >> e;

    int cx, cy, jx, jy;
    for (auto i = 0; i < 10; i ++ ) {
        for (int j = 0; j < 10; j ++ ) {
            if (g[i][j] == 'C') cx = i, cy = j;
            if (g[i][j] == 'F') jx = i, jy = j;
        }
    }

    auto outline = [](int x, int y) -> bool {
        return x < 0 || x >= 10 || y < 0 || y >= 10;
    };
    vector<array<int, 2>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    auto dfs = [&](auto &&dfs, int cx, int cy, int cd, int jx, int jy, int jd, int stp) -> int {
        if (cx == jx && cy == jy) return stp;
        if (stp > 10000) return 1e9;
        auto ncx = cx + dir[cd][0], ncy = cy + dir[cd][1];
        auto njx = jx + dir[jd][0], njy = jy + dir[jd][1];
        if (outline(ncx, ncy) || g[ncx][ncy] == '*') ncx = cx, ncy = cy, cd = (cd + 1) % 4;
        if (outline(njx, njy) || g[njx][njy] == '*') njx = jx, njy = jy, jd = (jd + 1) % 4;
        return dfs(dfs, ncx, ncy, cd, njx, njy, jd, stp + 1);
    };

    auto t = dfs(dfs, cx, cy, 0, jx, jy, 0, 0);
    cout << (t == 1e9 ? 0 : t) << endl;
    return 0;
}