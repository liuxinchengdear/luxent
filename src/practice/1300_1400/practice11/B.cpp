#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;

        vector<vector<int>> p(150);
        for (int i = 0; i < n; i ++ ) {
            p[s[i]].push_back(i);
        }

        bool fg = true;

        if (p['p'].size() && p['s'].size() && p['p'].front() < p['s'].front()) fg = false;

        for (auto i : p['s']) {
            if (!fg) break;
            auto it = lower_bound(p['p'].begin(), p['p'].end(), i);
            if (it != p['p'].begin()) { fg = false; break;}
            if (it != p['p'].end()) {
                auto d = *it - i + 1;
                if (n - i != d && *it + 1 != d) { fg = false; break; }
            }
        }

        cout << (fg ? "YES\n" : "NO\n");
    }
    return 0;
}