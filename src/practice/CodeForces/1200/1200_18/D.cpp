#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int ans = 0, st = 0;
        for (int i = 2; i <= n; i ++ ) {
            if (!st && a[i] != a[i - 1]) {
                st = a[i] > a[i - 1] ? 1 : -1;
                ans ++ ;
            }
            if (a[i] < a[i - 1] && st == 1) ans ++ , st = -1;
            if (a[i] > a[i - 1] && st == -1) ans ++ , st = 1;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}