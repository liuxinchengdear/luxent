#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n + 1); int las = 0;
        bool fg = false;
        for (int i = 1; i <= n; i ++ ) { auto &&c = s[i - 1];
            a[i] = c == 0x31 ? i : i + 1;
            if (a[i] == a[i - 1]) {
                a[i - 1] = las + 1;
                if (a[i - 1] == i - 1) fg = true;
            }
            if (c == 0x31) las = i;
        }
        if (a.back() > n) {
            a.back() = las + 1;
            if (a.back() == n) fg = true;
        }
        cout << (fg ? "NO\n" : "YES\n");
        if (!fg) {
            for (auto i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}