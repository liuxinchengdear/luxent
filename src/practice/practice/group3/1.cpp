#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> dp(20, vector<int>(20));
    auto dfs = [&](auto &&dfs, int que, int stk) -> int {
        if (!que) return 1;
        if (dp[que][stk]) return dp[que][stk];
        if (!stk) return dfs(dfs, que - 1, stk + 1);
        return dp[que][stk] = dfs(dfs, que - 1, stk + 1) + dfs(dfs, que, stk - 1);
    };

    cout << dfs(dfs, n, 0) << endl;
    return 0;
}