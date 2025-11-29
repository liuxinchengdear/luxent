#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> v(n), a(n);
        if (k == 1) {
            for (int i = 0; i < n; i ++ ) {
                int x; cin >> x;
                cout << (x & 1 ? x + 1 : x) << " \n"[i == n - 1];
            }
            continue;
        }
        else if (k == 2) {
            for (int i = 0; i < n; i ++ ) {
                int x; cin >> x;
                auto t = x % 3;
                cout << (t ? (t == 1 ? x + 2 : x + 4) : x) << " \n"[i == n - 1];
            }
            continue;
        }
        for (int i = 0; i < n; i ++ ) {
            cin >> a[i], v[i] = a[i] % (k - 1);
        }
        for (int i = 0; i < n; i ++ ) {
            cout << (v[i] ? a[i] + k * (k - 1 - v[i]) : a[i]) << " \n"[i == n - 1];
        }
    }
    return 0;
}