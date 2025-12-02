#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;

        string s; cin >> s;
        int D = count(s.begin(), s.end(), 'D'), R = count(s.begin(), s.end(), 'R');

        unordered_map<char, array<int, 2>> dir{{'D', {1, 0}}, {'R', {0, 1}}};

        vector<vector<int>> st(n + 1);

        auto outline = [&](int x, int y) -> bool {
            return x < 1 || x > n || y < 1 || y > m;
        };

        auto path = [&](int len, char ch) -> void {
            int cnt = 0, mx = len - 1 - (ch == 'D' ? D : R);
            int x = 1, y = 1; st[x].push_back(y);
            for (int i = 0; i < s.size(); i ++ ) { auto c = s[i];
                if (c == '?') c = ( ++ cnt) <= mx ? ch : ch == 'D' ? 'R' : 'D';

                x = x + dir[c][0], y = y + dir[c][1]; 
                st[x].push_back(y);
            }
        };
        
        path(n, 'D'); path(m, 'R');

        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            int l = st[i].front(), r = st[i].back();
            res += r - l + 1;
        }
        cout << res << endl;
    }
    return 0;
}