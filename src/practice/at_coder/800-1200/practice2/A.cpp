#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    n = a.size() - 1;
    if (m >= n) { cout << "0\n"; exit(0); }

    vector<int> diff;
    for (int i = 2; i <= n; i ++ ) { diff.push_back(a[i] - a[i - 1]); }

    sort(diff.begin(), diff.end());
    cout << accumulate(diff.begin(), diff.begin() + n - m, 0ll) << endl;
    return 0;
}