#include <bits/stdc++.h>
using namespace std;

#define int long long

void FILEIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 2);
        int res = 0;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 2; i <= n; i += 2) {
            a[i - 1] > a[i] ? res += a[i - 1] - a[i], a[i - 1] = a[i] : 0LL;
            int t = 0;
            a[i + 1] + a[i - 1] > a[i] ? t = a[i + 1] + a[i - 1] - a[i], res += t, a[i + 1] -= t : 0LL;
        }

        cout << res << '\n';
    }
    return 0;
}