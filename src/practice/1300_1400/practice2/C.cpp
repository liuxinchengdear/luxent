#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        vector<int> dp(n + 1); dp[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            dp[i] = (dp[i - 1] + (a[i] >= a[i - 1] && a[i] >= b[i - 1] && b[i] >= a[i - 1] && b[i] >= b[i - 1]) * dp[i - 1]) %  mod;
        }
        cout << dp[n] << endl;
    }
    return 0;
}