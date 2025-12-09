#include <bits/stdc++.h>
using namespace std;

using pci = pair<char, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p3(15); p3.front() = 1;
    for (int i = 1; i < 15; ++ i) p3[i] = p3[i - 1] * 3;

    int n; cin >> n;
    string s; cin >> s; s = " " + s;

    auto eval = [](string s) -> char {
        int a = count(s.begin(), s.end(), 0x31);
        return a >= 2 ? 0x31 : 0x30;
    };

    auto dfs = [&](auto &dfs, int l, int r) -> pci {
        int tot = r - l + 1, sub = tot / 3;
        if (sub == 1) {
            string ns = string(s.begin() + l, s.begin() + r + 1);
            int cnt = count(ns.begin(), ns.end(), ns.front());
            return { eval(ns), cnt == 3 || 0 ? 2 : 1 };
        }
        string str;
        auto [a, n1] = dfs(dfs, l, l + sub - 1); 
        auto [b, n2] = dfs(dfs, l + sub, l + 2 * sub - 1); 
        auto [c, n3] = dfs(dfs, l + 2 * sub, r);

        str += a; str += b; str += c;
        int sum = n1 + n2 + n3, res = 0;
        if (a == b && a == c) res = sum - max({n1, n2, n3});
        else res = a == b ? min(n1, n2) : a == c ? min(n1, n3) : min(n2, n3);

        return { eval(str), res };
    };

    cout << dfs(dfs, 1, p3[n]).second << endl;

    return 0;
}