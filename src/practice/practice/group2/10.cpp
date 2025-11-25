#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a(5010);

    int n; cin >> n; int mx = 0;
    for (int i = 0, x; i < n; i ++ ) cin >> x, a[x] ++ , mx = max(mx, x);

    int res = 0;
    for (int i = 2; i <= mx; i ++ ) { if (a[i] < 2) continue;
        for (int j = 1; j <= i / 2; j ++ ) {
            int k = i - j;
            auto t = 1ll * a[i] * (a[i] - 1) / 2 % mod;
            if (j == k) res = (res + 1ll * a[j] * (a[j] - 1) / 2 * t) % mod;
            else res = (res + 1ll * a[j] * a[k] * t) % mod;
        }
    }
    cout << res << endl;
    return 0;
}