#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        int l = 0, r = 0, c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] > b[i]) l += a[i];
            if (a[i] < b[i]) r += b[i];
            if (a[i] == b[i]) c1 += a[i] == 1, c2 += a[i] == -1;
        }

        if (c1 + c2 >= abs(l - r)) cout << (l + r + c1 - c2 >> 1) << endl;
        else cout << min(l, r) + c1 << endl;
    }
    return 0;
}