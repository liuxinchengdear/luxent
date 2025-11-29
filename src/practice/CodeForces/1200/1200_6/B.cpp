#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> a(m);
        for (int i = 0; i < m; i ++ ) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < q; i ++ ) {
            int num; cin >> num;
            auto p = lower_bound(a.begin(), a.end(), num);
            if (*p == num) cout << "0\n";
            else {
                if (p == a.begin()) cout << a[0] -1 << '\n';
                else if (p == a.end()) cout << n - a[m - 1] << '\n';
                else {
                    auto l = *prev(p), r = *p;
                    cout << (r - l >> 1) << '\n';
                }
            }
        } 
    }
    return 0;
}