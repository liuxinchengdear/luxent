#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 15;

int now;
int num[N], dp[N][N];

int dfs(int pos, int sum, bool lead, bool limit) {
    int ans = 0;
    if (pos == 0) return sum;
    if (!limit && !lead && dp[pos][sum] != -1) return dp[pos][sum];
    int up = limit ? num[pos] : 9;
    for (int i = 0; i <= up; i ++ ) {
        if (i == 0 && lead) ans += dfs(pos - 1, sum, true, limit && i == up);
        else if (i == now) ans += dfs(pos - 1, sum + 1, false, limit && i == up);
        else if (i != now) ans += dfs(pos - 1, sum, false, limit && i == up);
    }
    if (!lead && !limit) dp[pos][sum] = ans;
    return ans;
}

int solve(int x) {
    int len = 0;
    while (x) {
        num[ ++ len] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof dp);
    return dfs(len, 0, true, true);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;
    for (int i = 0; i <= 9; i ++ ) now = i, cout << solve(b) - solve(a - 1) << " \n"[i == 9];
    return 0;
}