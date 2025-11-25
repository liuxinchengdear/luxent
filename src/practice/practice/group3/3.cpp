#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c; 
    int dp[21][21][21] = {0};

    auto check = [](int a, int b, int c) -> bool {
        return a >= 0 && a <= 20 && b >= 0 && b <= 20 && c >= 0 && c <= 20;
    };

    auto dfs = [&](this auto &&dfs, int a, int b, int c) -> int {
        if (check(a, b, c) && dp[a][b][c]) return dp[a][b][c];
        if (a <= 0 || b <= 0 || c <= 0) return dp[0][0][0] = 1;
        if (a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);

        if (a < b && b < c) return dp[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
        return dp[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    };

    while (cin >> a >> b >> c, a != -1 || b != -1 || c != -1) {
        cout << format("w({}, {}, {}) = {}\n", a, b, c, dfs(a, b,c));
    }
    return 0;
}