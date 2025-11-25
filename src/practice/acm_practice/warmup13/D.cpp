#include <bits/stdc++.h>
using namespace std;

#define int long long

#define lowbit(x) ((x) & -(x))

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i ++ ) {
        int v; cin >> v;
        g[i].push_back(v); g[v].push_back(i);
    }

    int res = 0;

    auto dfs = [&](auto &&self, int u, int fa) -> int {
        if (u != 1 && g[u].size() == 1) {res += w[fa] ^ w[u]; return 1;}
        int sum = 1;
        for (auto v : g[u]) {
            if (fa == v) continue;
            sum += self(self, v, u);
        }
        res += sum * (w[fa] ^ w[u]);
        return sum;
    };

    dfs(dfs, 1, 0);

    cout << res << endl;
    
    return 0;
}