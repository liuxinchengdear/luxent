#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x; g[i].push_back(x);
    }

    vector<bool> st(n + 1);
    auto dfs = [&](auto &&dfs, int u, stack<int> &sk) -> void {
        if (st[u]) {
            vector<int> res{u}; 
            while (sk.size() && sk.top() != u) res.push_back(sk.top()), sk.pop();
            reverse(res.begin(), res.end());
            cout << res.size() << endl;
            for (auto e : res) cout << e << " ";
            exit(0);
        }
        st[u] = true; sk.push(u);
        for (auto v : g[u]) {
            dfs(dfs, v, sk);
        }
    };

    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) {
            stack<int> sk;
            dfs(dfs, i, sk);
        }
    }
}