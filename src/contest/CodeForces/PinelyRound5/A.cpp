#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int R, X, D, n; cin >> R >> X >> D >> n;
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i ++ ) { auto &c = s[i];
            if (c == 0x32 && R >= X) continue;
            R = max(0, R - D); cnt ++ ;
        }
        cout << cnt << endl;
    }
    return 0;
}