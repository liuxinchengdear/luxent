#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> dp(1010);
    auto dfs = [&](auto &&dfs, int num) -> int {
        if (num == 1) return 1;
        if (dp[num]) return dp[num];
        int sum = 1;
        for (int i = 1; i <= num / 2; i ++ ) sum += dfs(dfs, i);
        return dp[num] = sum;
    };

    cout << dfs(dfs, n) << endl;
    return 0;
}