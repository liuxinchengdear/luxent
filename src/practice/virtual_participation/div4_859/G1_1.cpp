#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        sort(a.begin(), a.end());
        if (a[1] != 1) {cout << "NO\n"; continue;}
        int ans = 0;
        bool fg = false;
        for (int i = 1; i <= n; i ++ ) {
            if (i == 1) {ans = 1; continue;}
            if (a[i] > ans) {fg = true; break;}
            ans += a[i];
        }
        cout << (fg ? "NO\n" : "YES\n");
    }
    return 0;
}