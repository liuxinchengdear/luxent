#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    sort(s.begin(), s.end());

    auto isthui = [](const string &s) -> bool {
        for (int i = 0; i < s.size() / 2; i ++ ) {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    };

    int res = 0;
    do {
        bool fg = true;
        for (int i = 0; i + k - 1 < n; i ++ ) {
            if (isthui(s.substr(i, k))) { fg = false; break; }
        }
        res += fg;
    } while (next_permutation(s.begin(), s.end()));

    cout << res << endl;
    return 0;
}