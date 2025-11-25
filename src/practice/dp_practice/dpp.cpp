#include <bits/stdc++.h>
using namespace std;

const int N = 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));

    int x, y, num; 
    while (cin >> x >> y >> num, x || y || num) g[x][y] = num;

    int dp[N][N][N][N] = {0};

    auto outline = [&](int x, int y) -> bool {
        return x < 1 || x > n || y < 1 || y > n;
    };

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}};

    dp[1][1][1][1] = g[1][1];
    for (int i = 1; i <= n; i ++ ) { for (int j = 1; j <= n; j ++ ) {
        for (int k = 1; k <= n; k ++ ) { for (int l = 1; l <= n; l ++ ) { if (i + j != k + l) continue;
            for (int ii = 0; ii < 2; ii ++ ) { for (int jj = 0; jj < 2; jj ++ ) {
                int ni = i + dir[ii][0], nj = j + dir[ii][1], nk = k + dir[jj][0], nl = l + dir[jj][1];
                if (outline(ni, nj) || outline(nk, nl)) continue;
                dp[i][j][k][l] = max(dp[i][j][k][l], dp[ni][nj][nk][nl] + vector<int>{g[i][j] + g[k][l], g[i][j]}[i == k && j == l]);
            }}
        }}
    }}

    cout << dp[n][n][n][n] << endl;
    return 0;
}