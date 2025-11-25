#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, y; cin >> x >> y;
        int t = y - 1;
        bool fg = false;
        while (t > x) {
            if (gcd(t, y) == 1 && gcd(t, x) == 1) {fg = true;cout << t << '\n'; break;}
            t -- ;
        }
        if (!fg) cout << "-1\n";
    }
    return 0;
}