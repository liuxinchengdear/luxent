#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    int mx = 0, mn = 1e9;
    for (int i = 1; i <= n; i ++ ) 
    {cin >> a[i]; mx = max(mx, a[i]); mn = min(mn, a[i]);}

    if (n <= 2) {cout << n << '\n'; return 0;}
    if (mx == mn) {cout << "2\n"; return 0;}
    int x = a[1], y = a[n]; if (x > y) swap(x, y);

    if (x == mn && y == mx) cout << "2\n";
    else if (x == mn || y == mx) cout << "3\n";
    else cout << "4\n";
    return 0;
}