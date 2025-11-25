#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int to, w; 
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<Edge>> g(n + 1);

    int mx = 0;
    for (int i = 0; i + 1 < n; i ++ ) {
        int u, v, w; cin >> u >> v >> w; mx = max(mx, w);
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }

    vector<int> poi(n + 1);

    auto check = [&](int pos) -> bool {
        poi[pos] = 1; 
        vector<bool> st(n + 1);
        queue<int> q; q.push(pos); st[pos] = true;

        while (q.size()) {
            auto u = q.front(); q.pop();
            for (auto [v, w] : g[u]) {
                if (st[v]) continue;
                poi[v] = w - poi[u];
                if (poi[v] <= 0) return false;
                q.push(v); st[v] = true;
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i ++ ) {
        if (check(i)) {
            cout << "YES\n";
            for (int i = 1; i <= n; i ++ ) cout << poi[i] << " \n"[i == n];
            return 0;
        }
    }
    cout << "NO\n";
    
    return  0;
}