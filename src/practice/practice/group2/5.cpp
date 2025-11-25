#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<string> a(n);
    for (auto &e : a) cin >> e;

    vector<vector<string>> g(10);
    for (auto e : a) {
        g[e.front() - 0x30].push_back(e);
    }

    for (int i = 1; i < 10; i ++ ) sort(g[i].begin(), g[i].end());

    string res = "0";
    vector<string> mx(10, "0");
    auto dfs = [&](auto &&dfs, int de, string s) -> void {
        if (de == 0) { res = max(res, s); return ; }
        
        if (!g[de].size()) { dfs(dfs, de - 1, s); return; }
        if (mx[de] != "0") { dfs(dfs, de - 1, s + mx[de]); return; }

        string tt = "0";
        do {
            string tmp;
            for (int i = 0; i < g[de].size(); i ++ ) tmp += g[de][i];
            dfs(dfs, de - 1, s + tmp); tt = max(tt, tmp);
        } while (next_permutation(g[de].begin(), g[de].end()));

        mx[de] = tt;
    };

    dfs(dfs, 9, "");
    cout << res << endl;
    return 0;
}