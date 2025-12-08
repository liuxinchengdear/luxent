#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int to, w;
};

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x; cin >> n >> m >> x;

    vector<vector<Edge>> g(2 * n + 1);

    for (int i = 0; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, 1}); g[v + n].push_back({u + n, 1});
    }

    for (int u = 1; u <= n; ++ u) {
        g[u].push_back({u + n, x}); g[u + n].push_back({u, x});
    }

    auto dijkstra = [&](int s) -> int {
        vector<int> dist(2 * n + 1, 1e18); dist[s] = 0;
        vector<bool> st(2 * n + 1); 
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        heap.push({0, s});

        while (heap.size()) {
            auto [dis, u] = heap.top(); heap.pop();
            if (st[u]) continue; st[u] = true;
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.push({dist[v], v});
                }
            }
        }

        return min(dist[n], dist[n << 1]);
    };

    cout << dijkstra(1) << endl;
    return 0;
}