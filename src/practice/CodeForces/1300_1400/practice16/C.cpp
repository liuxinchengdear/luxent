#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= m; i ++ ) cin >> b[i];

        vector<int> res{ 0 }; set<int> st;
        for (int i = 1; i <= m; i ++ ) {
            if (st.count(b[i])) continue;
            st.insert(b[i]); res.push_back(b[i]);
        }

        bool fg = true;
        for (int i = 1; i < min(n + 1, (int)res.size()); i ++ ) {
            if (res[i] != a[i]) { fg = false; break; }
        }
        cout << (fg ? "YA\n" : "TIDAK\n");
    }
    return  0;
}