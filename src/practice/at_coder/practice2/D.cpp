#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        queue<int> q; q.push(0);

        vector<bool> st(1 << n); st[0] = true;

        bool fg = false;
        while (q.size()) {
            auto t = q.front(); q.pop();
            if (t == (1 << n) - 1) {fg = true; break;}
            for (int i = 0; i < n; i ++ ) {
                if (!(t >> i & 1)) {
                    auto nt = t + (1 << i);
                    if (s[nt - 1] == 0x30 && !st[nt]) q.push(nt), st[nt] = true;
                }
            }
        }

        cout << (fg ? "Yes" : "No") << '\n';
    }
    return  0;
}