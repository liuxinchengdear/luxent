#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s; int n = s.size();

        if (n == 1) { cout << "1\n"; continue; }

        bool fg = false;
        for (int i = 0; i + 1 < n; i ++ ) {
            if (s[i] == '>' && s[i + 1] == '<') { fg = true; break; }
        }
        if (fg) { cout << "-1\n"; continue; }

        int t = count(s.begin(), s.end(), '*');
        if (t) {
            if (t > 1) cout << "-1\n";
            else {
                auto p = find(s.begin(), s.end(), '*') - s.begin();
                if (p >= 1 && s[p - 1] == '>' || p + 1 < n && s[p + 1] == '<') cout << "-1\n";
                else cout << max(p + 1, n - p) << '\n';
            }
        }
        else {
            int i = 0;
            while (i + 1 < n && s[i + 1] == s[i]) i ++ ;
            cout << max(i + 1, n - i - 1) << '\n';
        }
    }
    return 0;
}