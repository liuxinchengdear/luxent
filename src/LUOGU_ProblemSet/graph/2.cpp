#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<Edge>> g(n + 1);

    vector<int> d(n + 1);
    int u, v, w;
    while (cin >> u >> w) {
        int cnt = 0;
        while (cin >> v, v) cnt ++ , g[v].push_back({u, w}), d[u] ++ ;
        if (!cnt) g[v].push_back({u, w}), d[u] ++ ;
    }

    auto topsort = [&]() -> int {
        queue<int> q;
        vector<int> dist(n + 1);
        for (int i = 0; i <= n; i ++ ) if (!d[i]) q.push(i);
        
        int mx = 0;
        while (q.size()) {
            auto u = q.front(); q.pop();
            for (auto [v, w] : g[u]) {
                dist[v] = max(dist[v], dist[u] + w);
                mx = max(mx, dist[v]);
                if ( -- d[v] == 0) q.push(v);
            }
        }
        return mx;
    };

    cout << topsort() << endl;
    return 0;
}