#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; cin >> s >> t;

    if (s.size() == 1 || t.size() == 1) { cout << "-1\n"; exit(0); }
    
    vector<vector<int>> p(26);
    for (int i = 1; i < s.size(); i ++ ) p[s[i] - 0x61].push_back(i);

    bool fg = false; int ns, nt;
    int res = 1e9;
    for (int i = t.size() - 2; i >= 0; i -- ) {
        auto tc = t[i] - 0x61;
        if (p[tc].size()) { 
            fg = true;  
            if (res > t.size() - i + p[tc].front()) {
                res = t.size() - i + p[tc].front();
                ns = p[tc].front(), nt = i;
            }
        }
    }

    if (!fg) { cout << "-1\n"; exit(0); }
    cout << string(s.begin(), s.begin() + ns) + string(t.begin() + nt, t.end()) << '\n';

    return 0;
}