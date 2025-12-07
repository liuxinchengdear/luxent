#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        vector<array<int, 2>> dp(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            dp[i][0] = min(min(dp[i - 1][1], dp[i - 1][0]) - a[i], b[i] - max(dp[i - 1][0], dp[i - 1][1]));
            dp[i][1] = max(max(dp[i - 1][1], dp[i - 1][0]) - a[i], b[i] - min(dp[i - 1][0], dp[i - 1][1]));
        }

        cout << dp[n][1] << endl;
    }
    return 0;
}