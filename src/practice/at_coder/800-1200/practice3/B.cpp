#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, A, B; cin >> n >> A >> B;
    
    vector<vector<int>> dp(n + 1, vector<int>(A + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        int a, b; cin >> a >> b;
        for (int j = 0; j <= A; j ++ ) {
            if (j < a) { dp[i][j] = dp[i - 1][j] + b; continue; }
            dp[i][j] = min(dp[i - 1][j] + b, dp[i - 1][j - a]);
        }
    }

    for (int i = 1; i <= n; i ++ ) {
        auto t = *min_element(dp[i].begin(), dp[i].end());
        if (t > B) return cout << i - 1 << endl, 0;
    }
    return cout << n << endl, 0;
}