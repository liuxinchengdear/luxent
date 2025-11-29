#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<array<int, 2>> tmp{{1, 1}, {0, 1}, {1, 0}, {0, 0}};

        vector<int> mat{1, 3, 2, 0};

        auto dfs = [&](auto &&dfs, int de, int px, int py, int x, int y, int num) -> int {
            if (!de) return num;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + (1 << de - 1) * tmp[i][0], ny = y + (1 << de - 1) * tmp[i][1];
                if (px >= nx && py >= ny) return dfs(dfs, de - 1, px, py, nx, ny, num + mat[i] * (1 << de - 1) * (1 << de - 1));
            }
            return -1;
        };

        auto ndfs = [&](auto &&ndfs, int de, int x, int y, int num, int snum) -> pair<int, int> {
            if (num == snum) return {x, y};
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + (1 << de - 1) * tmp[i][0], ny = y + (1 << de - 1) * tmp[i][1];
                auto block = 1ll * (1 << de - 1) * (1 << de - 1);
                int lnum = snum + mat[i] * block, rnum = lnum + block - 1;
                if (num >= lnum && num <= rnum) return ndfs(ndfs, de - 1, nx, ny, num, lnum);
            }
            return {-1, -1};
        };

        int q; cin >> q;

        while (q -- ) {
            string op; cin >> op;
            if (op == "->") {
                int x, y; cin >> x >> y;
                cout << dfs(dfs, n, x, y, 1, 1, 1) << endl;
            }
            else {
                int x; cin >> x;
                auto [l, r] = ndfs(ndfs, n, 1, 1, x, 1);
                cout << l << " " << r << endl;
            }
        }
    }
    return 0;
}