#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 15;

int now;
int num[N], dp[N][N];

ll dfs(int pos, int sum, bool lead, bool limit) {
    if (!pos) return sum;
    if (!lead && !limit && dp[pos][sum] != -1) return dp[pos][sum];

    ll ans = 0;
    auto up = limit ? num[pos] : 9;

    for (int i = 0; i <= up; i ++ ) {
        auto flag = limit && i == up;
        if (i == 0 && lead) ans += dfs(pos - 1, sum, true, flag);
        else if (i == now) ans += dfs(pos - 1, sum + 1, false, flag);
        else ans += dfs(pos - 1, sum, false, flag);
    }
    if (!limit && !lead) dp[pos][sum] = ans;

    return ans;
}

ll count(int n, int x) {
    memset(dp, -1, sizeof dp);
    int len = 0;
    while (n) num[ ++ len] = n % 10, n /= 10;
    now = x;
    return dfs(len, 0, true, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; 
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; i ++ )
            cout << count(b, i) - count(a - 1, i) << " \n"[i == 9];
    }
    return 0;
}