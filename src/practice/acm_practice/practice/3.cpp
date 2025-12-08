#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c; cin >> a >> b >> c;

        vector<array<int, 2>> dp(b + 1);
        dp[0][0] = dp[0][1] = c;
        for (int i = 1; i <= b; i ++ ) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) * 2;
        }

        cout << max(dp[b][0], dp[b][1]) << endl;
    }
    return 0;

}