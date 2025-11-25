#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        int cnt = 0;
        map<int, int, greater<int>> mp;
        for (int i = 0; n; i ++ ) {
            mp[i] = n % 3; cnt += n % 3; n /= 3;
        }

        if (k < cnt) {cout << "-1\n"; continue;}

        for (auto &[key, v] : mp) {
            if (k <= cnt || !key) break;
            auto spa = k - cnt, mul = spa / 2;
            auto sub = min(mul, v);
            k -= sub << 1; v -= sub;
            mp[key - 1] += sub * 3;
        }

        int ans = 0;
        for (auto [key, v] : mp) {
            if (!v) continue;
            int fac = pow(3, key);
            ans += (fac * 3ll + fac / 3 * key) * v;
        }
        cout << ans << endl;
    }
    return 0;
}