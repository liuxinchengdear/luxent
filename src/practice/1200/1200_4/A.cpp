#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<pii> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i].first;
        for (int i = 0; i < n; i ++ ) cin >> a[i].second;

        int num = -1e9, res = 0;
        for (int i = 0; i < n; i ++ ) {
            auto [h, l] = a[i];
            res += max(h, l);
            num = max(num, min(h, l));
        }

        cout << res + num << '\n';

    }
    return 0;
}