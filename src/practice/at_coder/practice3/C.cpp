#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i ++ ) {
            int a, b, c; cin >> a >> b >> c;
            x += min(a, b), y += min(c, b), z += min(a + c, b);
        }

        auto check = [&](int num) -> bool {
            if (num > x) return false;
            if (num > y) return false;
            if (num << 1 > z) return false;
            return true;
        };

        auto binary_search = [&](int l, int r) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid)) l = mid + 1;
                else r = mid;
            }
            if (!check(l)) l -- ;
            return l;
        };

        cout << binary_search(0, z >> 1) << endl;
    }
    return 0;
}