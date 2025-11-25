#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i ++ )  {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        if (n == 2) {cout << "0\n"; continue;}

        int res = 0;
        for (auto i = 1; i <= n; i ++ ) res += int(g[i].size() == 1);

        int mx = 0;
        for (auto i = 1; i <= n; i ++ ) {
            int cnt = 0;
            for (auto e : g[i]) cnt += int(g[e].size() == 1);
            mx = max(mx, cnt);
        }

        cout << res - mx << endl;
    }
    return 0;
}