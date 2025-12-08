#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

struct Edge {
    int to, w;
};

struct Trie {
    vector<vector<int>> trie; int idx;

    Trie(int n, int m) {
        trie.resize(n);
        for (auto &e : trie) e.resize(m);
        idx = 0;
    }

    void insert(int num) {
        int p = 0;
        for (int i = 30; i >= 0; -- i) {
            auto u = num >> i & 1; auto &t = trie[p][u];
            if (!t) t = ++ idx;
            p = t;
        }
    }

    int query(int num) {
        int p = 0; int res = 0;
        for (int i = 30; i >= 0; -- i) {
            auto u = num >> i & 1; auto t = trie[p][1 - u];
            if (t) p = t, res += 1 << i;
            else p = trie[p][u];
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<Edge>> g(n + 1);

    for (int i = 1; i < n; i ++ ) {
        int u, v, w; cin >> u >> v >> w; 
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }

    vector<int> p;

    auto dfs = [&](auto &&dfs, int u, int fa, int num) -> void {
        p.push_back(num);
        for (auto [v, w] : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u, num ^ w);
        }
    };

    dfs(dfs, 1, -1, 0);

    Trie a(N, 2);
    for (auto e : p) a.insert(e);

    int res = 0;
    for (auto e : p) res = max(res, a.query(e));

    cout << res << endl;
    return 0;
}