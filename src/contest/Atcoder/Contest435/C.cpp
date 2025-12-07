#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    int p = 1;
    for (int i = 1; i <= min(p, n); i ++ ) {
        p = max(i + a[i] - 1, p);
    }

    cout << min(n, p) << endl;
    return 0;
}