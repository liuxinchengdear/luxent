#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

struct Edge {
    int to, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i ++ ) {
        int u, v, w; cin >> u >> v >> w; w += a[u] + a[v];
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }

    auto dijkstra = [&](int s) -> vector<int> {
        vector<int> dist(n + 1, 1e18); dist[s] = a[s];
        vector<bool> st(n + 1);
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        heap.push({dist[s], s});

        while (heap.size()) {
            auto [dis, u] = heap.top(); heap.pop();
            if (st[u]) continue; st[u] = true;
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w - a[u]) {
                    dist[v] = dist[u] + w - a[u];
                    heap.push({dist[v], v});
                }
            }
        }

        return dist;
    };

    auto dist = dijkstra(1);

    for (int i = 2; i <= n; i ++ ) cout << dist[i] << " \n"[i == n];
    return 0;
}