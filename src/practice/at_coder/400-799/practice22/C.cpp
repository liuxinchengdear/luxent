#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d; cin >> n >> m >> d;

    vector<int> a(n), b(m);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mx = -1;
    for (auto e : a) {
        auto l = lower_bound(b.begin(), b.end(), e - d), r = lower_bound(b.begin(), b.end(), e + d + 1);

        if (l != b.end() && abs(*l - e) <= d) mx = max(mx, *l + e);
        if (r != b.begin() && abs(*prev(r) - e) <= d) mx = max(mx, *prev(r) + e);
    }
    cout << mx << endl;
    return 0;
}