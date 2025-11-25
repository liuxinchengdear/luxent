#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto dfs = [&](this auto &&dfs) -> string {
        char c; string res;
        while (cin >> c) {
            if (c == '[') {
                int num; cin >> num;
                string s = dfs();
                string tmp;
                while (num -- ) tmp += s;
                res += tmp; continue;
            }
            if (c == ']') return res;
            res += c;
        }
        return res;
    };

    cout << dfs() << endl;
    return 0;
}