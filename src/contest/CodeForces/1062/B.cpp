#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        sort(s.begin(), s.end()); sort(t.begin(), t.end());
        if (s == t) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}