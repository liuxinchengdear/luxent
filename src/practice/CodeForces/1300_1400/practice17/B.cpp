#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _luxent_T; cin >> _luxent_T; while (_luxent_T -- ) {
        int n; cin >> n;

        auto check = [&](string s, int cnt) -> bool {
            if (cnt > 2 * n) return true;
            cout << "? " << s << endl;
            int x; cin >> x; return x;
        };

        unordered_map<string, bool> mp;

        int cnt = 0;

        auto dfs = [&](this auto &&dfs, int len, string s, int op) -> bool {
            if (len == n) return cout << "! " << s << endl, true;
            
            if (op) {
                bool f1 = mp.count("0" + s) ? mp["0" + s] : mp["0" + s] = check("0" + s, ++ cnt);
                if (f1 && dfs(len + 1, "0" + s, op)) return true;
                bool f2 = mp.count("1" + s) ? mp["1" + s] : mp["1" + s] = check("1" + s, ++ cnt);
                if (f2 && dfs(len + 1, "1" + s, op)) return true;
                return dfs(len, s, 1 - op);
            }
            else {
                bool f1 = mp.count(s + "0") ? mp[s + "0"] : mp[s + "0"] = check(s + "0", ++ cnt);
                if (f1 && dfs(len + 1, s + "0", op)) return true;
                bool f2 = mp.count(s + "1") ? mp[s + "1"] : mp[s + "1"] = check(s + "1", ++ cnt);
                if (f2 && dfs(len + 1, s + "1", op)) return true;
                return dfs(len, s, 1 - op);
            }
        };

        dfs(0, "", 0);
    }
    return 0;
}