#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto fast_pow = [&](int a, int n) -> int {
        a %= mod; 
        if (!a) return 0;
        int res = 1;
        while (n) {
            if (n & 1) res = 1ll * res * a % mod;
            a = 1ll * a * a % mod; n >>= 1;
        }
        return res;
    };

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<int> suff(n + 2);
        for (int i = n; i ; i -- ) suff[i] = suff[i + 1] + a[i];

        int sum = 0;
        for (int i = 1; i < n; i ++ ) sum = (sum + suff[i + 1] % mod * a[i]) % mod;

        int q = n * (n - 1) / 2;

        q = fast_pow(q, mod - 2);
        cout << sum * q % mod << endl;
    }
    return 0;
}