#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a;
        pair<int, int> res; bool fg = false;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; if (fg) continue;
            if (!a.size()) { a.push_back(x); continue; }
            for (auto e : a) {
                if (x % e % 2 == 0) { res = {e, x}; fg = true; break; }
            }
            a.push_back(x);
        }
        if (fg) cout << res.first << " " << res.second << endl;
        else cout << "-1\n";
    }
    return 0;
}