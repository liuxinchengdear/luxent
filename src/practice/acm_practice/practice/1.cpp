#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp(N + 1); dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; ++ i) {
        if (i & 1) {
            if (!dp[i - 1] || !dp[i - 2]) dp[i] = 1;
        }
        else {
            dp[i] = !dp[i - 1];
        }
    }

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
    return 0;
}