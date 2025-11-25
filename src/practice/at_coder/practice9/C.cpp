#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<array<int, 2>> dp(n + 1);

    dp[0][1] = -4e9;
    for (int i = 1; i <= n; i ++ ) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 2 * a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}