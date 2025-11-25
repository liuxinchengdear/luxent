#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200010, mod = 998244353;

int f[N], F[N], p2[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for (int i = 1; i < N; i ++ ) p2[i] = p2[i - 1] * 2 % mod;

    f[3] = 2; F[3] = 1;
    for (int i = 4; i < N; i ++ ) f[i] = (3 * f[i - 1] + 2) % mod, F[i] = (F[i - 1] + f[i] - (p2[i - 2] - 1)) % mod;
    
    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int sum = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
        sort(a.begin() + 1, a.end());

        int res = 0;
        for (int i = 3; i <= n; i ++ ) res = (res + F[i] * p2[n - i] % mod * a[i] % mod) % mod;

        cout << (res + p2[n - 1] * sum % mod) % mod << '\n';
    }
    return 0;
}