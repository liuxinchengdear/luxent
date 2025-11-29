#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        vector<int> ta = a, tb = b;
        sort(ta.begin(), ta.end()); sort(tb.begin(), tb.end());

        int ans = 0; vector<pii> res;
        for (int i = 1; i <= n; i ++ ) {
            int pa = 0, pb = 0;
            for (int j = 1; j <= n; j ++ ) {
                if (!pa && a[j] == ta[i]) pa = j;
                if (!pb && b[j] == tb[i]) pb = j;
            }
            for (int j = pa - 1; j >= i; j -- ) swap(a[j], a[j + 1]), ans ++ , res.emplace_back(1, j);
            for (int j = pb - 1; j >= i; j -- ) swap(b[j], b[j + 1]), ans ++ , res.emplace_back(2, j);
        }

        for (int i = 1; i <= n; i ++ ) if (a[i] > b[i]) ans ++ , res.emplace_back(3, i);
        cout << ans  << endl;
        for (auto [op, x] : res) cout << op << " " << x << '\n';
    }
    return 0;
}