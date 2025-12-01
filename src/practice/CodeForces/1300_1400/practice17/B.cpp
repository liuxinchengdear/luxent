#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        auto check = [](string s) -> bool {
            cout << "? " << s << endl;
            int x; cin >> x; return x;
        };

        unordered_map<string, bool> mp;

        auto dfs = [&](this auto &&dfs, int len, string s) -> bool {
            if (len == n) return cout << "! " << s << endl, true;
            
            if (check("0" + s) && dfs(len + 1, "0" + s)) return true;
            if (check("1" + s) && dfs(len + 1, "1" + s)) return true;

            return false;
        };

        dfs(0, "");
    }
    return 0;
}