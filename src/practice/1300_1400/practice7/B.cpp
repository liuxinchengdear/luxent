#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        if (!n) { cout << "YES\n"; continue; }
        
        string s = bitset<30>(n).to_string();

        s = s.substr(s.find(0x31));

        auto t = lowbit(n), cnt = -1;
        while (t) ++ cnt, t >>= 1;

        s = string(cnt, 0x30) + s;

        if ((s.size() & 1) && s[s.size() >> 1] == 0x31) { cout << "NO\n"; continue; }
        
        bool fg = true;
        for (int i = 0; i < s.size() >> 1; i ++ ) {
            if (s[i] != s[s.size() - 1 - i]) { fg = false; break; }
        }

        cout << (fg ? "YES\n" : "NO\n");
    }
    return 0;
}