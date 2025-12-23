#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        
        string s; 
        vector<string> a(n); for (auto &e : a) cin >> e;

        vector<array<string, 2>> dp(n + 1);
        for (int i = 1; i <= n; ++ i) {
            dp[i][0] = a[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        }

        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}