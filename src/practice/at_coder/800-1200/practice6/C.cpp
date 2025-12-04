// #include <bits/stdc++.h>
// using namespace std;

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int _T; cin >> _T; while (_T -- ) {
//         int n, m, k; cin >> n >> m >> k; k <<= 1;
//         string s; cin >> s; s = " " + s;

//         vector<vector<int>> g(n + 1);
//         for (int i = 0; i < m; i ++ ) {
//             int a, b; cin >> a >> b;
//             g[a].push_back(b);
//         }

//         vector<vector<int>> dp(k + 2, vector<int>(n + 1, -1));

//         auto dfs = [&](auto &&dfs, int u, int dep) -> void {
//             if (dep == k + 1) { dp[dep][u] = s[u] == 'A'; return; }
//             bool fg = false;
//             for (auto v : g[u]) {
//                 dfs(dfs, v, dep + 1);
//                 if (dep & 1 && dp[dep + 1][v] == 1) fg = true;
//                 if (dep % 2 == 0 && !dp[dep + 1][v]) fg = true;
//             }
//             dp[dep][u] = dep & 1 ? (fg ? 1 : 0) : (fg ? 0 : 1);
//         };

//         bool fg = false;
//         for (int i = 1; i <= n; ++ i) if (dp[k][i] == 1) fg = true;

//         cout << (fg ? "Alice\n" : "Bob\n") << endl;
//     }

//     return 0;
// }