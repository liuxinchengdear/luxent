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

    int n; cin >> n;
    vector<vector<Edge>> g(n + 1);

    for (int i = 1; i < n; i ++ ) {
        int a, b, x; cin >> a >> b >> x;
        g[i].push_back({i + 1, a}); g[i].push_back({x, b});
    }

    auto dijkstra = [&](int s) -> int {
        vector<int> dist(n + 1, 1e18); dist[s] = 0;
        vector<bool> st(n + 1);
        priority_queue<pii, vector<pii>, greater<pii>> heap; heap.push({0, s});
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

        return dist[n];
    };

    cout << dijkstra(1) << endl;
    return 0;
}