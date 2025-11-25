#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1); 
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];

        vector<int> d(n + 1);
        for (int i = 2; i <= n; i ++ ) d[i] = d[i - 1] + (a[i] != a[i - 1]);

        while (q -- ) {
            int l, r; cin >> l >> r;
            auto cnt = pre[r] - pre[l - 1];
            if (cnt % 3 || (r - l + 1 - cnt) %  3) cout << "-1\n";
            else {
                auto ans = r - l + 1; ans /= 3;
                if (r - l == d[r] - d[l]) cout << ans + 1 << endl;
                else cout << ans << endl;
            }
        }
    }
    return 0;
}