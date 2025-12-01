#include <bits/stdc++.h>
using namespace std;

// a + b + c

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int n = s.size(); s = " " + s;

    if (n == 1) return cout << "NO\n", 0;

    for (int l = 2; l < n; l ++ ) {
        for (int r = l; r < n; r ++ ) {
            string a = string(s.begin() + 1, s.begin() + l);
            string b = string(s.begin() + l, s.begin() + r + 1);
            string c = string(s.begin() + r + 1, s.end());

            if (a + b == b + c) return cout << "YES\n" << a + b << endl, 0;
        }
    }
    return cout << "NO\n", 0;
}