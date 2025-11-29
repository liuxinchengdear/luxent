#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), dp(n + 1), id(n + 1);
        vector<vector<int>> v(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            v[a[i]].push_back(i);
            id[i] = v[a[i]].size();
        }
        // for (int i = 1; i <= n; i ++ ) cout << id[i] << " \n"[i == n];
        for (int i = 1; i <= n; i ++ ) {
            dp[i] = dp[i - 1];
            if (id[i] >= a[i]) {
                dp[i] = max(dp[i - 1], dp[v[a[i]][id[i] - a[i]] - 1] + a[i]);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}