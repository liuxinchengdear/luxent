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

        vector<int> pre(n + 1), suff(n + 2);
        for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];
        for (int i = n; i ; i -- ) suff[i] = suff[i + 1] + a[i];

        while (q -- ) {
            int l, r, k; cin >> l >> r >> k;
            int ans = pre[l - 1] + suff[r + 1] + 1ll * (r - l + 1) * k;
            cout << (ans & 1 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}