#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R; cin >> R;

    auto check = [&](int x, int h) -> bool {
        auto nx = x + 0.5, ny = h + 0.5;
        return nx * nx + ny * ny <= 1ll * R * R;
    };

    auto binary_search = [&](int l, int r, int h) -> int {
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, h)) l = mid + 1;
            else r = mid;
        }
        if (!check(l, h)) l -- ;
        return l;
    };

    int res = 0;
    for (int h = 0; h <= R; h ++ ) {
        int tmp = binary_search(0, R, h) + 1;
        res += max(2 * (tmp * 2 - 1), 0ll);
    }
    res -= (binary_search(0, R, 0) + 1) * 2 - 1;
    cout << res << endl;
    
    return 0;
}