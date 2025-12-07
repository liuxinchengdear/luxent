#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        sort(a.begin() + 1, a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        n = a.size() - 1;

        vector<bool> st(n + 1); vector<int> res;
        bool fg = true;
        for (int i = 1; i <= n && fg; i ++ ) {
            if (!st[i]) {
                res.push_back(a[i]);
                for (int j = a[i] << 1; j <= k; j += a[i]) {
                    auto p = lower_bound(a.begin(), a.end(), j);
                    if (p == a.end() || *p != j) { fg = false; break; }
                    st[p - a.begin()] = true;
                }
            }
        }

        if (!fg) { cout << "-1\n"; continue; }
        cout << res.size() << endl;
        for (auto e : res) cout << e << " "; cout << endl;
    }
    return 0;
}