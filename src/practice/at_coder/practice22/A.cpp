#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

// 简单dp
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z; cin >> x >> y >> z;
    string s; cin >> s;

    int n = s.size();
    vector<pii> a;
    for (int i = 0; i < n; i ++ ) {
        int cnt = 1;
        while (i + 1 < n && s[i] == s[i + 1]) cnt ++ , i ++ ;
        a.emplace_back(s[i], cnt);
    }

    // for (auto [c, cnt] : a) cout << c << " " << cnt << endl;
    
    n = a.size();
    vector<array<int, 2>> dp(n + 1); dp.front()[1] = z;
    for (int i = 1; i <= n; i ++ ) {
        auto [c, cnt] = a[i - 1];
        if (c == 0x41) {
            dp[i][0] = min(dp[i - 1][1] + x * cnt + z, min(dp[i - 1][0] + 2 * z + x * cnt, dp[i - 1][0] + y * cnt));
            dp[i][1] = min(dp[i - 1][1] + x * cnt, min(dp[i - 1][0] + z + x * cnt, dp[i - 1][0] + y * cnt + z));
        }
        else {
            dp[i][0] = min(dp[i - 1][0] + x * cnt, min(dp[i - 1][1] + z + x * cnt, dp[i - 1][1] + y * cnt + z));
            dp[i][1] = min(dp[i - 1][1] + 2 * z + x * cnt, min(dp[i - 1][0] + z + x * cnt, dp[i - 1][1] + y * cnt));
        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}