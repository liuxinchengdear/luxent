#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        sort(a.begin() + 1, a.end());
        bool fg = true;
        for (int i = 1; i < n; i ++ ) {
            if (i % 2 == 0 && a[i + 1] > a[i]) { fg = false; break; } 
        }
        cout << (fg ? "YES\n" : "NO\n");
    }
    return 0;
}