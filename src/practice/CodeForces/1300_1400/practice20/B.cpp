#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); 
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<array<int, 2>> dp(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            dp[i][0] = min(dp[i - 1][0] + a[i], abs(dp[i - 1][1] + a[i]));
            dp[i][1] = max(dp[i - 1][1] + a[i], abs(dp[i - 1][0] + a[i]));
        }
        cout << dp[n][1] << endl;
    }
    return 0;
}