#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, d, k; cin >> n >> d >> k;

        vector<int> a(n + 2);
        for (int i = 0; i < k; i ++ ) {
            int l, r; cin >> l >> r;
            a[max(1, l - d + 1)] ++ ; a[r + 1] -- ;
        }

        int mx = -1, mn = 1e9; int bro, mon;
        for (int i = 1; i <= n - d + 1; i ++ ) {
            a[i] += a[i - 1];
            if (a[i] < mn) mn = a[i], mon = i;
            if (a[i] > mx) mx = a[i], bro = i;
        }

        cout << bro << " " << mon << endl;
    }
    return 0;
}