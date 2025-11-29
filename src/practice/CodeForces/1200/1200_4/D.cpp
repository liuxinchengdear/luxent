#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, m; cin >> x >> m;
        int res = 0;
        for (int y = 1; y <= min(m, (x << 1) - 1); y ++ ) {
            if (y == x) continue;
            auto t = x ^ y;
            res += x % t == 0 || y % t == 0;
        }
        cout << res << '\n';
    }
    
    return 0;
}