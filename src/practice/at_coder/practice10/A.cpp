#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N][N][N];

int dp[N][N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            for (int k = 1; k <= n; k ++ ) {
                auto &x = a[i][j][k]; cin >> x;
                dp[i][j][k] = x + dp[i - 1][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i - 1][j - 1][k] - dp[i - 1][j][k - 1] - dp[i][j - 1][k - 1] + dp[i - 1][j - 1][k - 1];
            }
        }
    }

    int q; cin >> q;
    while (q -- ) {
        int i1, i2, j1, j2, k1, k2; cin >> i1 >> i2 >> j1 >> j2 >> k1 >> k2;

        cout << dp[i2][j2][k2] - dp[i1 - 1][j2][k2] - dp[i2][j1 - 1][k2] - dp[i2][j2][k1 - 1] + dp[i1 - 1][j1 - 1][k2] + dp[i1 - 1][j2][k1 - 1] + dp[i2][j1 - 1][k1 - 1] - dp[i1 - 1][j1 - 1][k1 - 1] << endl;;
    }
    return 0;
}