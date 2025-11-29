#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];

        sort(a.begin(), a.end());

        int res = 0;
        for (int i = 0; i < n - 1; i ++ ) {
            auto p1 = lower_bound(a.begin() + i + 1, a.end(), (sum - a[i] - y));
            auto p2 = lower_bound(a.begin() + i + 1, a.end(), (sum - a[i] - x + 1));
            if (p1 == a.end()) continue;
            p2 = prev(p2);
            res += p2 - p1 + 1;
        }
        cout << res << '\n';
    }
    return 0;
}