#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> a(3, vector<int>(n + 1));
        vector<vector<pii>> dp(3, vector<pii>(n + 1));
        for (int i = 1; i <= 2; i ++ ) {
            for (int j = 1; j <= n; j ++ ) cin >> a[i][j];
        }
        for (int i = 0; i <= n; i ++ ) dp[0][i].second = 2e9;
        dp[1][0].first = dp[2][0].first = 2e9;

        dp[1][1] = {a[1][1], a[1][1]};
        dp[2][1] = {min(a[1][1], a[2][1]), max(a[1][1], a[2][1])};
        for (int j = 2; j <= n; j ++ ) {
            for (int i = 1; i <= 2; i ++ ) {
                auto &[mn, mx] = dp[i][j];
                mn = max(dp[i][j - 1].first, dp[i - 1][j].first);
                mn = min(mn, a[i][j]);
                mx = min(dp[i][j - 1].second, dp[i - 1][j].second);
                mx = max(mx, a[i][j]);
            }
        }

        auto [mn, mx] = dp[2][n];
        cout << (mn * (2 * n - mx + 1)) << endl;
    }
    return 0;
}