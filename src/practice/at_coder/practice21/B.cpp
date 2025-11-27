#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<int> alls(a.begin() + 1, a.end());
    int q; cin >> q;
    vector<pii> qey(q);
    for (int i = 0; i < q; i ++ ) {
        int l, r; cin >> l >> r;
        qey[i] = {l, r}; alls.push_back(l); alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    vector<int> p(alls.size()); vector<bool> st(alls.size());

    for (int i = 2; i <= n; i += 2) {
        int l = lower_bound(alls.begin(), alls.end(), a[i]) - alls.begin(), r = lower_bound(alls.begin(), alls.end(), a[i + 1]) - alls.begin();
        for (int j = l + 1; j <= r; j ++ ) st[j] = true;
    }

    for (int i = 1; i < alls.size(); i ++ ) {
        p[i] = p[i - 1];
        if (st[i]) p[i] = p[i - 1] + alls[i] - alls[i - 1];
    }

    for (auto [l, r] : qey) {
        l = lower_bound(alls.begin(), alls.end(), l) - alls.begin(), r = lower_bound(alls.begin(), alls.end(), r) - alls.begin();
        cout << p[r] - p[l] << endl;
    }
    return 0;
}