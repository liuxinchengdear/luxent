#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    auto mul = [](string a, string b) -> string {
        reverse(a.begin(), a.end()); reverse(b.begin(), b.end());

        vector<int> res(a.size() + b.size());
        for (int i = 0; i < b.size(); i ++ ) {
            for (int j = 0; j < a.size(); j ++ ) {
                int da = a[j] - 0x30, db = b[i] - 0x30;
                int pro = da * db;
                res[i + j] += pro; 
                res[i + j + 1] += res[i + j] / 10; res[i + j] %= 10;
            }
        }
        while (res.size() > 1 && !res.back()) res.pop_back();
        reverse(res.begin(), res.end());
        string c;
        for (auto e : res) c.push_back(e + 0x30);
        return c.substr(max(0, int(c.size() - 500)));
    };

    auto fast_pow = [&](string a, int n) -> string {
        string res = "1";
        while (n) {
            if (n & 1) res = mul(res, a);
            a = mul(a, a); n >>= 1;
        }
        return res;
    };
    
    cout << int(log10(2) * n + 1) << endl;

    string res = fast_pow("2", n); res.back() = res.back() - 1;

    string s;
    s = res.size() >= 500 ? "" : string(500 - res.size(), 0x30);
    s = s + (res.size() > 500 ? res.substr(res.size() - 500) : res);
    for (int i = 0; i < 10; i ++ ) {
        for (int j = 0; j < 50; j ++ ) {
            int idx = i * 50 + j; cout << s[idx];
        }cout << '\n';
    }
    return 0;
}