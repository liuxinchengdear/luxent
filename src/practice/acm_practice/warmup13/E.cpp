#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> w(n + 1); int mx = 0;
        for (int i = 1; i <= n; i ++ ) cin >> w[i], mx = max(mx, w[i]);

        vector<vector<int>> g(n + 1);

        for (int i = 0; i < m; i ++ ) {
            int u, v; cin >> u >> v;
            if (u != v) g[u].push_back(v); g[v].push_back(u);
        }

        auto check = [&](int x) -> bool {
            vector<int> fa(n + 1); iota(fa.begin(), fa.end(), 0);
            auto getfa = [&](auto &&self, int x) -> int {
                return x == fa[x] ? fa[x] : fa[x] = self(self, fa[x]);
            };

            vector<int> cnt(n + 1 , 1);

            auto dfs = [&](auto &&self, int u, int fat, int x) -> void {
                for (auto v : g[u]) {
                    if (v == fat) continue;
                    if (w[v] >= x && w[u] >= x) {
                        int nu = getfa(getfa, u), nv = getfa(getfa, v);
                        if (nu != nv) fa[nu] = nv, cnt[nv] += cnt[nu];
                    }
                    self(self, v, u);
                }
            };

            for (int i = 1; i <= n; i ++ ) if (fa[i] == i && cnt[i] >= k) return true;
            return false;
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

        cout << binary_search(1, mx) << endl;
    }
    return  0;
}