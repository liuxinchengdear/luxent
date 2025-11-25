#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n); string s;
    for (auto &e : a) cin >> e; cin >> s;

    vector<vector<int>> dp(k + 1, vector<int>(n, -1));

    auto dfs = [&](auto &&self, int de, int num) -> int {
        if (de == k) {return dp[de][num] = a[num];}

        if (dp[de][num] != -1) return dp[de][num];

        int sum = s[de] == 's' ? 0 : 1;
        for (int i = 0; i < n; i ++ ) {
            auto t = self(self, de + 1, (num + i) % n);
            s[de] == 's' ? sum = (sum + t) % mod : sum = 1ll * sum * t % mod;
        }
        return dp[de][num] = sum;
    };

    cout << dfs(dfs, 0, 0) << '\n';
    return 0;
}