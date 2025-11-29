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

        if (n == 2) {cout << min(a[1], a[2]) << '\n'; continue;}

        int res = min(a[1], a[2]);
        for (int len = 3; len <= 3; len ++ ) {
            for (int i = 1; i <= n - len + 1; i ++ ) {
                int j = i + len - 1;
                vector<int> tmp(a.begin() + i, a.begin() + j + 1);
                nth_element(tmp.begin(), tmp.begin() + (len - 1) / 2, tmp.end());
                res = max(res, tmp[len - 1 >> 1]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}