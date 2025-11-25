#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n + 1); int sum = 0;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    
    vector<int> l = a, r = a;
    sort(l.begin() + 1, l.end()); sort(r.begin() + 1, r.end(), greater<int>());

    int mx = 0, mn = 0;
    for (int i = 1, s = 0; i <= n; i ++ ) s += l[i], mn = min(mn, s);
    for (int i = 1, s = 0; i <= n; i ++ ) s += r[i], mx = max(mx, s);

    if (k > sum) {
        if (k <= 0) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i = 1; i <= n; i ++ ) cout << l[i] << " \n"[i == n];
        }
    }
    else {
        cout << "Yes\n";
        for (int i = 1; i <= n; i ++ ) cout << r[i] << " \n"[i == n];
    }
    return 0;
}