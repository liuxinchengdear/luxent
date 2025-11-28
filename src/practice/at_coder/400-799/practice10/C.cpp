#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 
    string s; cin >> s; s = " " + s;

    string succ = "SPR", faild = "PRS", ori = "RSP";
    vector<array<int, 3>> dp(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
            if (faild[j] == s[i]) { dp[i][j] = -1; continue; }
            int p1 = (j + 1) % 3, p2 = (j + 2) % 3;
            if (s[i - 1] != faild[p1]) dp[i][j] = dp[i - 1][p1] + (s[i] == succ[j]);
            if (s[i - 1] != faild[p2]) dp[i][j] = max(dp[i][j], dp[i - 1][p2] + (s[i] == succ[j]));
        }
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}