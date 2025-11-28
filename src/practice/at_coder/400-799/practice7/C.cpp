#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> a(n);

    vector<vector<int>> res;

    auto dfs = [&](auto &&dfs, int de, int num) -> void {
        if (de == n) {res.push_back(a); return;}

        for (int i = num; i + (n - de - 1) * 10 <= m; i ++ ) {
            a[de] = i;
            dfs(dfs, de + 1, i + 10);
        }
    };

    dfs(dfs, 0, 1);

    cout << res.size() << endl;
    for (auto E : res) {
        for (int i = 0; i < n; i ++ ) cout << E[i] << " \n"[i == n - 1];
    }
    return 0;
}