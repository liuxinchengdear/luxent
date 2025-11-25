#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"
#define lowbit(x) x & (-x)
#define fi first
#define se second
using LL = long long;
using ULL = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using PII = pair<int, int>;
using PLI = pair<LL, int>;
const int N = 1e5 + 10, M = 39989, P = 998244353;
const LL INF = 2e18;
const double eps = 1e-10;
const double PI = acos(-1);

template <typename... Args>
void o(const Args&... args) {
    ((cout << args << " "), ...);
    cout << endl;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 3>>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].push_back({v, x, y});
        adj[v].push_back({u, x, y});
    }
    int l = 0, r = n + 1;
    vector<int> p(n + 1);
    auto dfs = [&](this auto &&dfs, int u, int fa) -> void {
        for (auto [v, x, y] : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);
            if ((v > u) ^ (x > y)) p[v] = --r;
            else p[v] = ++l;
        }
    };
    dfs(1, 0);
    p[1] = ++l;
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << endl;
}



signed main() {
    //freopen("data.in", "r", stdin);
    //freopen("std.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}