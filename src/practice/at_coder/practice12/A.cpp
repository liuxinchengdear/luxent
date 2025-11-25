#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> a(n);

    for (int i = 0; i < n; i ++ ) {
        int l, r; cin >> l >> r;
        a[i] = {l, r};
    }

    sort(a.begin(), a.end(), [](pii x, pii y) -> bool {
        return x.second < y.second;
    });

    auto [st, ed] = a.front();
    for (int i = 1; i < n; i ++ ) {
        auto [l, r] = a[i];
        if (l <= ed) ed = max(ed, r);
        else st = l, ed = r;
    }
    
}