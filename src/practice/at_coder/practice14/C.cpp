#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int len; cin >> len; string s; cin >> s;

    vector<string> g(n); 
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    auto outline = [&](int x, int y) -> bool {
        return x < 0 || x >= n || y < 0 || y >= m;
    };

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    unordered_map<int, int> op{{'U', 0}, {'D', 3}, {'L', 1}, {'R', 2}};

    auto dfs = [&](auto &&dfs, int x, int y, int de) -> bool {
        if (outline(x, y) || g[x][y] == '#') return false;
        if (de == len) return true;
        int d = op[s[de]];
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if (dfs(dfs, nx, ny, de + 1)) return true;
        return false;
    };

    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            res += dfs(dfs, i, j, 0);
        }
    }

    cout << res << endl;
    return 0;  
}