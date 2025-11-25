#include <bits/stdc++.h>
using namespace std;

#define int long long

string operator ^ (const string &a, const string &b) {
    string res = a.size() > b.size() ? a : b;
    int len = min(a.size(), b.size());
    for (int i = 1; i <= len; i ++ ) {
        res[res.size() - i] = ((a[a.size() - i] - 0x30) ^ (b[b.size() - i] - 0x30)) + 0x30;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s;
        
        int pos = -1;
        for (int i = 1; i < s.size(); i ++ ) {
            if (s[i] == 0x30) {pos = i; break;}
        }

        if (pos == -1) cout << "1 1 1 " << s.size() << '\n';
        else {
            string res = string(s.size(), 0x30);
            int l, r;
            for (int i = 0; i < pos; i ++ ) {
                int len = (int)s.size() - pos;
                string t = s.substr(i, len);
                string tmp = t ^ s;
                if (res < tmp) res = tmp, l = i + 1, r = l + len - 1;
            }
            cout << 1 << " " << s.size() << " " << l << " " << r << '\n';
        }
    }

    return 0;
}