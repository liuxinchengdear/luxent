#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        unordered_map<int, int> mp;
        string tmp;
        bool fg = false;
        for (int i = 0; i < n; i ++ ) {
            auto c = s[i];
            if (mp.count(c)) {
                if (mp[c] == tmp.back()) {fg = true; break;}
                else tmp.push_back(mp[c]);
            }
            else {
                auto t = i ? 1 - tmp.back() : 0;
                mp[c] = t, tmp.push_back(t);
            }
        }
        cout << (fg ? "NO\n" : "YEs\n");
    }
    return 0;
}