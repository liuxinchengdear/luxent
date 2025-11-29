#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, y, z, k; cin >> x >> y >> z >> k;
        int res = -1;
        for (int i = 1; i <= x; i ++ ) {
            for (int j = 1; j <= y; j ++ ) {
                auto t = i * j;
                if (k % t) continue;
                int zz = k / t;
                res = max(res, (x - i + 1) * (y - j + 1) * (z - zz + 1));
            }
        }
        cout << ( ~ res ? res : 0) << '\n';
    }
    return 0;
}