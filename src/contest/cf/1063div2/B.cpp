#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), p(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], p[a[i]] = i;
        
        string s; cin >> s; s = " " + s;
        if (s[1] == 0x31 || s[n] == 0x31 || s[p[1]] == 0x31 || s[p[n]] == 0x31) { cout << "-1\n"; continue; }

        cout << "5\n";
        cout << "1 " << p[n] << '\n';
        cout << "1 " << p[1] << '\n';
        cout << p[1] << " " << n << '\n';
        cout << p[n] << " " << n << '\n';
        cout << min(p[1], p[n]) << " " << max(p[1], p[n]) << '\n';
    }
    return 0;
}