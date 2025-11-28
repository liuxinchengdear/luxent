#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> rec(m); vector<char> res(m);
    for (int i = 0; i < m; i ++ ) {
        int num, x; cin >> num;
        while (num -- ) cin >> x, rec[i].push_back(x);
        cin >> res[i];
    }

    int ans = 0;
    for (int i = 0; i < 1 << n; i ++ ) {
        set<int> st;
        for (int j = 0; j < n; j ++ ) {
            if (i >> j & 1) st.insert(j + 1);
        }

        bool fg = true;
        for (int i = 0; i < m; i ++ ) { auto &E = rec[i];
            int cnt = 0;
            for (auto e : E) cnt += st.count(e);
            if (cnt < k && res[i] == 'o' || cnt >= k && res[i] == 'x') { fg = false; break; }
        }
        ans += fg;
    }
    cout << ans << endl;
    return 0;
}