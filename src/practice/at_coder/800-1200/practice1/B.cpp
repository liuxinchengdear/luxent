#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s; s = " " + s;

    vector<array<int, 2>> dp(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        auto c = s[i];
        dp[i][0] = c == 0x30 ? 1 + dp[i - 1][1] : dp[i - 1][0];
        dp[i][1] = c == 0x31 ? 1 + dp[i - 1][1] : dp[i - 1][0];
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) sum += dp[i][1];
    cout << sum << endl;;
    return 0;
}