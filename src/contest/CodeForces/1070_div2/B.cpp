#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;

        int res = 0;
        for (int i = 0; i < n; ++ i) {
            if (s[i] == 0x30) {
                int p = i;
                while (s[i % n] == 0x30) ++ i;
                res = max(res, i - p);
                if (i >= n) break;
            }
        }

        cout << res << endl;
    }
    return 0;
}