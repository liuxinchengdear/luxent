#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;

        vector<vector<int>> a(n + 1, vector<int>(m + 1));

        vector<pii> p;
        int mx = -1;
        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= m; j ++ ) {
                cin >> a[i][j], mx = max(mx, a[i][j]);
            }
        
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (a[i][j] == mx) p.emplace_back(i, j);
            }
        }
        map<int, vector<int>> row, col;
        int r = 0, c = 0;

        for (auto [a, b] : p) {
            row[a].push_back(b) ; col[b].push_back(a);
            r = max((size_t)r, row[a].size()); c = max((size_t)c, col[b].size());
        }

        int flag = false;
        map<int, int> rr, cc;
        bool st = true;
        for (auto [id, e] : row) {
            if (e.size() == r && st) {st = false; continue;}
            for (auto num : e) rr[num] ++ ;
        }
        if (rr.size() <= 1) flag = true;

        st = true;
        for (auto [id, e] : col) {
            if (e.size() == c && st) {st = false; continue;}
            for (auto num : e) cc[num] ++ ;
        }
        if (cc.size() <= 1) flag = true;
        cout << (flag ? mx - 1 : mx) << '\n';
    }
    return 0;
}