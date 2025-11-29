#include <bits/stdc++.h>
using namespace std;

// 邻接矩阵

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1));

    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    vector<int> a(n + 1); iota(a.begin(), a.end(), 0);

    int res = 1e9;
    do {
        bool fg = true;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] == i || a[a[i]] == i) { fg = false; break; }
        }

        if (!fg) continue;

        int cnt = 0;
        for (int i = 1; i <= n; i ++ ) cnt += !g[i][a[i]];

        res = min(res, cnt + m - (n - cnt));
    } while (next_permutation(a.begin() + 1, a.end()));

    cout << res << endl;
    return 0;
}