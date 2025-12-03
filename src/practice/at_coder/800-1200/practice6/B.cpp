#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n; 
        string s; cin >> s;

        int c0 = count(s.begin(), s.end(), 0x30), c1 = count(s.begin(), s.end(), 0x31);

        int l0 = 0, l1 = 0;
        for (int i = 0; i < n; i ++ ) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j ++ ;
            l0 = max(l0, (s[i] == 0x30) * (j - i)); 
            l1 = max(l1, (s[i] == 0x31) * (j - i)); 
            i = j - 1;
        }

        if (c0 * c1 == 0) { cout << "0\n"; continue; }

        // cout << c0 << " " << c1 << " " << l0 << " " << l1 << endl;

        cout << min(c1 + 2 * (c0 - l0), c0 + 2 * (c1 - l1)) << endl;
    }
    return 0;
}