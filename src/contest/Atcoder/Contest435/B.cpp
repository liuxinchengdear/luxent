#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for  (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];

    int res = 0;
    for (int l = 1; l <= n; ++ l) {
        for (int r = l; r <= n; ++ r) {
            int sum = pre[r] - pre[l - 1];
            bool fg = true;
            for (int i = l; i <= r; i ++ ) {
                if (sum % a[i] == 0) { fg = false; break; }
            }
            res += fg;
        }
    }

    cout << res << endl;
    return 0;
}