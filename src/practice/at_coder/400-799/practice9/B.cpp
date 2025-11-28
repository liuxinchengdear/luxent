#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> x(n), p(n), alls;
    for (int i = 0; i < n; i ++ ) cin >> x[i], alls.push_back(x[i]);
    for (int i = 0; i < n; i ++ ) cin >> p[i];

    int q; cin >> q;

    vector<int> l(q), r(q);
    for (int i = 0; i < q; i ++ ) {
        cin >> l[i] >> r[i];
        alls.push_back(l[i]); alls.push_back(r[i]);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    int len = alls.size();
    vector<int> a(len + 1);
    for (int i = 0; i < n; i ++ ) {
        auto pos = lower_bound(alls.begin(), alls.end(), x[i]) - alls.begin();
        a[pos + 1] = p[i];
    }

    vector<int> pre(len + 1);
    for (int i = 1; i <= len; i ++ ) pre[i] = pre[i - 1] + a[i];

    for (int i = 0; i < q; i ++ ) {
        int nl = lower_bound(alls.begin(), alls.end(), l[i]) - alls.begin();
        int nr = lower_bound(alls.begin(), alls.end(), r[i]) - alls.begin();
        
        cout << pre[nr + 1] - pre[nl] << endl;
    }
    return 0;
}