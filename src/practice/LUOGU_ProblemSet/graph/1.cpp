#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int u, w, v; cin >> u >> w;
        int tmp = 0;
        while (cin >> v, v) tmp = max(tmp, ans[v]);
        ans[u] = tmp + w;
    }
    cout << ans[n] << endl;
    return 0;
}