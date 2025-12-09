#include <bits/stdc++.h>
using namespace std;

ostream& operator << (ostream &cout, const vector<int> &x) {
    for (auto e : x) cout << e << " ";
    return cout;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); int d = 0;
        for (int i = 1; i <= n; ++ i) cin >> a[i], d = gcd(d, a[i]);

        int mx = -1;
        for (int i = 1; i <= n; ++ i) a[i] /= d, mx = max(mx, a[i]);

        int cnt = count(a.begin() + 1, a.end(), 1);

        if (cnt) { cout << n - cnt << endl; continue; }

        vector<int> dp(mx + 1, 1e9); 
        for (int i = 1; i <= n; ++ i) dp[a[i]] = 1;

        for (int i = 1; i <= mx; ++ i) {
            if (dp[i] == 1e9) continue;
            for (int j = 1; j <= mx; ++ j) {
                int t = gcd(i, j);
                dp[t] = min(dp[t], dp[i] + dp[j]);
            }
        }

        cout << dp[1] + n - 2 << endl;
    }
    return 0;
}