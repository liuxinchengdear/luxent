#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;
        using pii = pair<int, int>;

        pii mt1 = make_pair(0, 0), mt2 = make_pair(0, 0);
        auto update = [&](int x, pii &mt) -> void {
            auto &[a, b] = mt;
            if (!a) {a = b = x; return;}
            if (a > b) swap(a, b);
            a = min(a, x); b = max(b, x);
        };

        int sm1 = 0, sm2 = 0;
        for (int i = 0, x; i < n; i ++ ) cin >> x, sm1 += x, update(x, mt1);
        for (int i = 0, x; i < m; i ++ ) cin >> x, sm2 += x, update(x, mt2);
        
        auto [mx1, mn1] = mt1; if (mx1 < mn1) swap(mx1, mn1);
        auto [mx2, mn2] = mt2; if (mx2 < mn2) swap(mx2, mn2);

        int mx = max(mx1, mx2), mn = min(mn1, mn2);

        auto t = sm1 + max(mn1, mx2) - mn1;
        
        cout << (k & 1 ? t : t + mn - mx) << '\n';
    }
    return 0;
}