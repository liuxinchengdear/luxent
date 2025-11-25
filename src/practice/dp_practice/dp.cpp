#include <bits/stdc++.h>
using namespace std;

// →_→
// 一种是正序关系，另一种是倒序关系，取决于// 你想怎么记忆化

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    int x, y, num;
    while (cin >> x >> y >> num, x || y || num) g[x - 1][y - 1] = num;

    vector<array<int, 2>> dir{{0, 1}, {1, 0}};

    auto outline = [&n](int x, int y) -> bool {
        return x >= n || x < 0 || y >= n || y < 0;
    };

    vector<vector<int>> mem(n * n, vector<int>(n * n, -1));
    
    auto dfs = [&](auto &&dfs, int u1, int u2) -> int {
        if (mem[u1][u2] != -1) return mem[u1][u2];

        auto a = u1 / n, b = u1 % n, c = u2 / n, d = u2 % n;
        if (a == n - 1 && b == n - 1) return mem[u1][u2] = g[a][b]; 

        int res = 0;
        for (int i = 0; i < 2; i ++ ) { auto na = a + dir[i][0], nb = b + dir[i][1]; if (outline(na, nb)) continue;
            for (int j = 0; j < 2; j ++ ) { auto nc = c + dir[j][0], nd = d + dir[j][1]; if (outline(nc, nd)) continue;
                auto n1 = na * n + nb, n2 = nc * n + nd;
                res = max(res, dfs(dfs, n1, n2) + vector<int>{g[a][b] + g[c][d], g[a][b]}[u1 == u2]);
            }
        }
        return mem[u1][u2] = res;
    };

    cout << dfs(dfs, 0, 0) << endl;
    
    return 0;
}