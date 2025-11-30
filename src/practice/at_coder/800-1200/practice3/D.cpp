#include <bits/stdc++.h>
using namespace std;

// [l, r] = s1[r + 1] + p1[l - 1] + (p0[r] - p0[l - 1])

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        if (s == " " + string(n, 0x30)) { cout << "0\n"; continue; }

        vector<int> p1(n + 1), p0(n + 1), s0(n + 2), s1(n + 2);
        for (int i = 1; i <= n; i ++ ) p1[i] = p1[i - 1] + (s[i] == 0x31), p0[i] = p0[i - 1] + (s[i] == 0x30);
        for (int i = n; i ; i -- ) s1[i] = s1[i + 1] + (s[i] == 0x31), s0[i] = s0[i + 1] + (s[i] == 0x30);

        vector<int> tmp(n + 1);
        for (int l = 1; l <= n; l ++ ) tmp[l] = p1[l - 1] - p0[l - 1];
        
        int res = 1e9;
        for (int r = 1, mn = 1e9; r <= n; r ++ ) mn = min(mn, tmp[r]), res = min(res, s1[r + 1] + p0[r] + mn);

        cout << res << endl;
    }
    return 0;
}