#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str = "nunhehheh"; str = " " + str;

    auto fast_pow = [](int a, int n) -> int {
        int res = 1;
        while (n) {
            if (n & 1) res = 1ll * res * a % mod;
            a = 1ll * a * a % mod; n >>= 1;
        }
        return res;
    };

    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s;
        int len = s.size(); s = " " + s;
        vector<array<int, 10>> dp(len + 1), pre(len + 1);

        for (int i = 1; i <= len; i ++ ) {
            for (int j = 1; j <= 9; j ++ ) {
                pre[i][j] = pre[i - 1][j];
                if (s[i] == str[j]) {
                    dp[i][j] = j == 1 ? (pre[i][j] = (pre[i][j] + 1) % mod, 1) : (pre[i][j] = (pre[i][j] + pre[i - 1][j - 1]) % mod, pre[i - 1][j - 1]);
                }
            }
        }

        vector<int> suff(len + 2);
        for (int i = len; i ; i -- ) suff[i] = suff[i + 1] + (s[i] == 'a');

        int res = 0;
        for (int i = 1; i <= len; i ++ ) res = (res + 1ll * dp[i][9] * (fast_pow(2, suff[i + 1]) - 1) % mod) % mod;
        cout << res << endl;
    }
    return 0;
}