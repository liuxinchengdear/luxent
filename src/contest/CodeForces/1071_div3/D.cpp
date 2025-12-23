#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<array<int, 2>> tmp{{1, 1}, {1, 0}, {0, 1}, {0, 0}};

        auto check = [&](int l, int r, int d, int mid, bool fg) -> int {
            int res = 0;
            for (int i = 0; i < d; ++ i) {
                if (l >> i & 1) res += 1 << i;
            }
            res <<= d + mid;
            if (fg) res += ((1 << mid) - 1) << d;
            for (int i = 0; i < d; ++ i) {
                if (r >> i & 1) res += 1 << i;
            }
            return res;
        };

        auto dfs = [&](this auto &&dfs, int d) -> void {
            if (d > n) return;
            int L = 1 << (d >> 1);
            vector<int> tmp{L + (1 << (d >> 1) - 1), (1 << (d >> 1) - 1)};

            if (d == 2) {
                cout << check(tmp.front() / L, tmp.front() % L, d >> 1, n - d, true) << " ";
                cout << check(tmp.back() / L, tmp.back() % L, d >> 1, n - d, true) << " ";
                for (int i = 0; i <= (1 << d) - 1; ++ i) if (i != tmp.front() && i != tmp.back()) cout << check(i / L, i % L, d >> 1, n - d, true) << " ";
            }
            else {
                cout << check(tmp.back() / L, tmp.back() % L, d >> 1, n - d, true) << " ";
                for (int i = 0; i < (1 << d) - 1; ++ i) if (i != tmp.back()) cout << check(i / L, i % L, d >> 1, n - d, true) << " ";
            }

            
            if (d + 1 == n) {
                for (int i = 0; i <= (1 << d) - 1; ++ i) cout << check(i / L, i % L, d >> 1, n - d, false) << " ";
            }
            dfs(d + 2);
        };

        if (n == 1) { cout << "1 0\n"; continue; }

        dfs(2); cout << endl;
    }
    return 0;
}