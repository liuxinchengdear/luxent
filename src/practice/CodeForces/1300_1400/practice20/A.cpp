#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        if (n == 2) { cout << stoi(s) << endl; continue; }

        string tmp = string(s.begin(), s.begin() + 2);
        for (int i = 2; i <= n; i ++ ) tmp += '?', tmp += s[i];

        int res = 261;

        auto eval = [&] -> void {
            stack<int> op, num;

            auto calcu = [&] -> void {
                auto b = num.top(); num.pop();
                auto a = num.top(); num.pop();
                auto c = op.top(); op.pop();

                int d = c == '+' ? a + b : a * b;
                d = min(d, (int)1e9);
                num.push(d);
            };

            for (int i = 1; i < s.size(); ++ i) {
                if (isdigit(s[i])) {
                    if (i + 1 < s.size() && isdigit(s[i + 1])) {
                        int d = stoi(string(s.begin() + i, s.begin() + i + 2)); ++ i;
                        num.push(d);
                    }
                    else num.push(s[i] - 0x30);
                }
                else {
                    auto c = s[i];
                    if (c == '+') {
                        while (op.size()) calcu();
                        op.push('+');
                    }
                    else {
                        if (op.size() && op.top() == '*') calcu();
                        op.push('*');
                    }
                }
            }

            while (op.size()) calcu();
            res = min(res, num.top());
        };

        vector<int> num(n << 1);

        auto dfs = [&](this auto &&dfs, int dep) -> void {
            if (dep == 2 * n - 1) { eval(); return; }
            if (s[dep] == '?') {
                s[dep] = '*'; dfs(dep + 1);
                s[dep] = '+'; dfs(dep + 1);
                s[dep] = '?';
            }
            else dfs(dep + 1);
        };

        for (int i = 2; i < tmp.size(); i += 2) {
            s = string(tmp.begin(), tmp.begin() + i) + string (tmp.begin() + i + 1, tmp.end());
            dfs(1);
        }

        cout << res << endl;
    }
    return 0;
}