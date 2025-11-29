#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> g(n + 1);

        vector<int> d(n + 1);
        for (int i = 1; i < n; i ++ ) {
            int u, v, x, y; cin >> u >> v >> x >> y;
            if (x <= y) g[u].push_back(v), d[v] ++ ;
            else g[v].push_back(u), d[u] ++ ;
        }

        auto topsort = [&]() -> vector<int> {
            vector<int> top; queue<int> q;
            for (int i = 1; i <= n; i ++ ) if (!d[i]) q.push(i), top.push_back(i);

            while (q.size()) {
                auto size = q.size(); 
                while (size -- ) {
                    auto u = q.front(); q.pop();
                    for (auto v : g[u]) {
                        if ( -- d[v] == 0) q.push(v), top.push_back(v);
                    }
                }
            }

            return top;
        };
        
        vector<int> num = topsort();

        vector<int> ans(n + 1); int cnt = 0;
        for (auto u : num) ans[u] = ++ cnt;

        for (int i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];
    }
    return 0;
}