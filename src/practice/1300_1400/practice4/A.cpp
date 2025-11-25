#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> fa(2 * n + 1); iota(fa.begin(), fa.end(), 0);

        auto getfa = [&](auto &&getfa, int x) -> int {
            return x == fa[x] ? fa[x] : fa[x] = getfa(getfa, fa[x]);
        };

        vector<int> ans;

        for (int i = 1; i <= n; i ++ ) {
            int u, v; cin >> u >> v;
            u = getfa(getfa, u), v = getfa(getfa, v);
            if (u != v) fa[u] = v, ans.push_back(i);
        }

        cout << ans.size() << endl;
        for (auto e : ans) cout << e << " "; cout << endl;
    }
    return 0;
}