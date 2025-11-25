#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++ ) a[i] += a[i - 1];

    while (q -- ) {
        int x; cin >> x;
        auto p = lower_bound (a.begin(), a.end(), x + 1) - a.begin();

        cout << p - 1 << endl;
    }
    return 0;
}