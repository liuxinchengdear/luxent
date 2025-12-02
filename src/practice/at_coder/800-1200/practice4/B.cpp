#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) cin >> g[i][j];
    }

    vector<vector<bool>> st(n + 1, vector<bool>(m + 1));

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > m;
    };

    auto dfs = [&](auto &&dfs) -> int {
        int num = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (!st[i][j]) num ^= g[i][j];
            }
        }
        
        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (!outline(i - 1, j) && !st[i - 1][j] && !st[i][j]) {
                    st[i - 1][j] = st[i][j] = true;
                    res = max(res, dfs(dfs));
                    st[i - 1][j] = st[i][j] = false;
                }
                if (!outline(i, j - 1) && !st[i][j - 1] && !st[i][j]) {
                    st[i][j - 1] = st[i][j] = true;
                    res = max(res, dfs(dfs));
                    st[i][j - 1] = st[i][j] = false;
                }
            }
        }
        return max(num, res);
    };

    cout << dfs(dfs) << endl;
    return 0;
}