#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);

        map<int, vector<int>> mp; mp[0].push_back(0);

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i]; 

            if (!a[i]) { mp[0].push_back(i); dp[i] = dp[i - 1] + 1; continue; }

            a[i] += a[i - 1];
            dp[i] = mp[a[i]].size() ? max(dp[mp[a[i]].back()] + 1, dp[i - 1]) : dp[i - 1];
            mp[a[i]].push_back(i);
        }

        cout << dp[n] << endl;
    }
    return 0;
}