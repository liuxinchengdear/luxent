#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 20;

ll num[N], dp[N];

ll dfs(int pos, int nat, int cnt, bool lead, bool limit) {
    if (!pos) return cnt > 1 ? 1 : 0;
    if (!lead && !limit && dp[pos] != -1) return dp[pos];

    ll ans = 0;
    auto up = limit ? num[pos] : 9;

    for (int i = 0; i <= up; i ++ ) {
        if (nat == -1 || (i & 1) != (nat & 1)) {
            auto flag = limit && i == up;
            if (i == 0 && lead) ans += dfs(pos - 1, -1, cnt, true, flag);
            else ans += dfs(pos - 1, i & 1, cnt + 1, false, flag);
        }
    }
    if (!limit && !lead) dp[pos] = ans;

    return ans;
}

bool check(ll n, ll pos) {
    ll len = 0;
    while (n) num[ ++ len] = n % 10, n /= 10;
    return dfs(len, -1, 0, true, true) >= pos;
}

ll find(ll pos) {
    ll l = 10, r = 2e18;

    while (l < r) {
        ll mid = l + r >> 1;
        if (check(mid, pos)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    ll pos; cin >> pos;
    cout << find(pos) << endl;

    system("pause");
    return 0;
}