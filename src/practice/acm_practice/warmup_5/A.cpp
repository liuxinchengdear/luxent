#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, k; cin >> a >> b >> k;

        auto fast_pow = [](int a, int n, int mod) -> int {
            int res = 1;
            while (n) {
                if (n & 1) res = 1ll * res * a % mod;
                a = 1ll * a * a % mod; n >>= 1;
            }
            return res;
        };

        auto n1 = fast_pow(2, k >> 1, mod) * a, n2 = fast_pow(2, k >> 1, mod) * b;
        if (k & 1) cout << n1 + n2 << " " << n1 - n2 << '\n';
        else cout << n1 << " " << n2 << '\n';
    }
    return 0;
}