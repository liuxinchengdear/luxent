#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> h[i];

    vector<vector<int>> dp(n + 1, vector<int>(n));

    if (n == 1) {cout << "1\n"; return 0;}

    int mx = 0;
    for (int j = 1; j < n; j ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            if (i <= j) {dp[i][j] = 1; continue;}
            dp[i][j] = h[i] == h[i - j] ? dp[i - j][j] + 1 : 1;
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}