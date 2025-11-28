#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> fa(n + 1), poi(n + 1);
    vector<int> s(n + 1);
    iota(fa.begin(), fa.end(), 0);

    auto getfa = [&](auto &&self, int x) -> int {
        return x == fa[x] ? fa[x] : fa[x] = self(self, fa[x]);
    };

    for ( ; q -- ; ) {
        int op, u, v; cin >> op;
        if (op == 1) {
            cin >> u >> v;
            u = getfa(getfa, u), v = getfa(getfa, v);
            if (u != v) fa[u] = v, s[v] += s[u];
        }
        else if (op == 2) {
            cin >> v;
            poi[v] ++ ;
            int vv = getfa(getfa, v);
            poi[v] & 1 ? s[vv] ++ : s[vv] -- ;
        }
        else {
            cin >> v;
            v = getfa(getfa, v);
            cout << (s[v] ? "Yes\n" : "No\n");
        }
    }
    return 0;
}