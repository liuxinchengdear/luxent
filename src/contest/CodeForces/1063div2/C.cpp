#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> g(2, vector<int>(n));

        vector<vector<pii>> p(n << 1 | 1);

        for (auto &E : g) for (auto &e : E) cin >> e;

        array<set<int>, 2> a;
        // 哨兵节点
        a.front().insert(1e9); a.back().insert(-1e9);

        for (int i = 0; i < 2; i ++ ) {
            for (int j = 0; j < n; j ++ ) { auto x = g[i][j]; 
                a[i].insert(j); p[x].emplace_back(i, j);
            }
        }

        auto add = [&](int x) -> void {
            for (auto [i, j] : p[x]) {
                a[i].erase(j);
            }
        };

        auto del = [&](int x) -> void {
            for (auto [i, j] : p[x]) {
                a[i].insert(j);
            }
        };

        auto succ = [&] -> bool {
            if (a.front().count(0) || a.back().count(n - 1)) return false;
            if (*a.front().begin() - 1 <= *a.back().rbegin()) return false;
            return true;
        };

        int r = 0, ans = 0;
        for (int l = 1; l <= n << 1; l ++ ) {
            while (r + 1 <= n * 2 && !succ()) add( ++ r);
            if (!succ()) break;

            ans += 2 * n - r + 1;
            del(l);
        }
        cout << ans << endl;
    }
    return 0;
}