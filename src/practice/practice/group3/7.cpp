#include <bits/stdc++.h>
using namespace std;

const int mod = 10000;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> dp(n + 1);

    dp[1] = 1; dp[2] = 3; dp[3] = 5;
    auto dfs = [&](auto &&dfs, int n) -> int {
        if (dp[n]) return dp[n];
        int cnt = dfs(dfs, n - 2);
        cnt = (cnt + 3) % mod;
        cnt = (cnt + dfs(dfs, n - 2)) % mod;
        return dp[n] = cnt;
    };

    cout << dfs(dfs, n) << endl;
    return 0;
}