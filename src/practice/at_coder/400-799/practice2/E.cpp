#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];

    for ( ; q -- ; ) {
        int b; cin >> b;
        auto p = lower_bound(a.begin(), a.end(), b);
        if (p == a.end()) cout << "-1\n";
        else {
            int cnt = p - a.begin() - 1;
            int res = pre[cnt] + (n - cnt) * (b - 1) + 1;
            cout << res << '\n';
        }
    }
    return 0;
}