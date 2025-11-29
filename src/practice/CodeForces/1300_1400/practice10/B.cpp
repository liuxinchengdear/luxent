#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        vector<int> a(n + 2);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        if (n == k) {
            int res = n / 2 + 1;
            for (int i = 1; i << 1 <= k; i ++ ) {
                if (a[i << 1] != i) { res = i; break; }
            } 
            cout << res << endl;
        }
        else { // x + k - 2 <= n
            vector<int> tmp(a.begin() + 2, a.begin() + n - k + 3);

            sort(tmp.begin(), tmp.end());
            cout << (tmp.back() == 1 ? 2 : 1) << endl;
        }
    }
    return 0;
}