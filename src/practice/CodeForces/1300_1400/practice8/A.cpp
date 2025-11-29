#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (auto &e : a) cin >> e;

        sort(a.begin(), a.end());

        vector<int> l(a.begin(), a.end() - k), r(a.begin() + k, a.end());

        int m = n - k;
        if (m & 1) cout << r[m >> 1] - l[m >> 1] + 1 << endl;
        else cout << r[m >> 1] - l[m - 1 >> 1] + 1 << endl;
    }
    return 0;
}