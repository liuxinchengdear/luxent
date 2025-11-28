#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2, m; cin >> n1 >> n2 >> m;

    vector<vector<int>> g(n1 + n2 + 1);
    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }

    auto dijkstra = [&](int s) -> int {
        vector<int> dist(n1 + n2 + 1, 1e9); dist[s] = 0;
        vector<bool> st(n1 + n2 + 1);
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        heap.push({0, s});

        while (heap.size()) {
            auto [dis, u] = heap.top(); heap.pop();
            if (st[u]) continue; st[u] = true;
            for (auto v : g[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    heap.push({dist[v], v});
                }
            }
        }

        int mx = 0;
        for (int i = 1; i <= n1 + n2; i ++ ) {
            if (dist[i] != 1e9) mx = max(mx, dist[i]);
        }
        return mx;
    };

    auto t1 = dijkstra(1), t2 = dijkstra(n1 + n2);
    cout << t1 + t2 + 1 << endl;
}