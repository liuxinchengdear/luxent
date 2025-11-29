#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(26);
        int mx = 0;
        for (auto e : s) a[e - 0x61] ++ , mx = max(mx, a[e - 0x61]);
        cout << max((n & 1 ? 1ll : 0ll), 2 * mx - n) << '\n';
    }
    return 0;
}