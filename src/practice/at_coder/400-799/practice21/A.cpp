#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<array<int, 2>> dp(n + 1);

    for (int i = 1; i <= n; i ++ ) {
        int x, y; cin >> x >> y;
        if (!x) dp[i][0] = max(dp[i - 1][1] + y, max(dp[i - 1][0], dp[i - 1][0] + y)), dp[i][1] = dp[i - 1][1];
        else dp[i][0] = dp[i - 1][0], dp[i][1] = max(dp[i - 1][0] + y, dp[i - 1][1]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}