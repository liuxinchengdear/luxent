#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i ++ ) {
            int a, b; cin >> a >> b;
            g[a].push_back(b); g[b].push_back(a);
        }

        vector<int> poi(n + 1);
        auto dfs = [&](auto &&self, int u, int fa) -> int {
            if (u != 1 && g[u].size() == 1) return poi[u] = 1;
            int sum = 0;
            for (auto v : g[u]) {
                if (v == fa) continue;
                sum += self(self, v, u);
            }
            return poi[u] = sum;
        };

        dfs(dfs, 1, -1);

        int m; cin >> m;
        for (; m -- ; ) {
            int a, b; cin >> a >> b;
            cout << poi[a] * poi[b] << '\n';
        }
    }
    return 0;
}