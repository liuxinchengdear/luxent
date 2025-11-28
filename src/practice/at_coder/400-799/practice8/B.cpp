#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    vector<bool> st(n + 1);
    queue<int> q; q.push(1); st[1] = true;

    int floor = -1;
    while (q.size()) {
        auto size = q.size(); 
        if ( ++ floor > n) break; 
        while (size -- ) {
            auto u = q.front(); q.pop();
            if (floor && u == 1) { cout << floor << endl; exit(0); }
            st[u] = false;
            for (auto v : g[u]) {
                if (!st[v]) q.push(v), st[v] = true;
            }
        }
    }
    cout << "-1\n";
    return 0;
}