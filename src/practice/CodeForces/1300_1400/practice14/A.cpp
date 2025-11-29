#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<bool> st(n + 1);

        auto dfs = [&](this auto &&dfs, int x) -> int {
            if (st[x]) return 0;
            st[x] = true;
            return dfs(a[x]) + 1;
        };

        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (!st[i]) res += dfs(i) - 1 >> 1;
        }
        cout << res << endl;
    }
    return 0;
}