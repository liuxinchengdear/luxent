#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int l, r; cin >> l >> r;

        auto cal_len = [](int x) -> int {
            if (!x) return 1;
            for (int i = 0; ; ++ i) if (1 << i > x) return i;
            return -1;
        };

        vector<int> a(r + 1);

        auto dfs = [&](this auto &&dfs, int l, int r) -> int {
            if (l >= r) return 0;
            int len = cal_len(r), d = (1 << len) - (r - l + 1);

            for (int i = d, num = r; i <= r; ++ i) a[i] = num -- ;

            return ((1 << len) - 1) * (r - l + 1 - d) + dfs(0, d - 1);
        };

        cout << dfs(l, r) << endl;

        for (auto e : a) cout << e << " "; cout << endl;
    }
    return 0;
}