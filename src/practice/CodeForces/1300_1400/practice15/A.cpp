#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        string s = "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 13 12 12 1 13";

        if ((n & 1) && n < 27) { cout << "-1\n"; continue; }

        if (n & 1) {
            cout << s << " ";
            n -= 27; n /= 2;
            for (int i = 0; i < n; i ++ ) cout << i + 14 << " " << i + 14 << " "; cout << '\n';
            continue;
        }

        n /= 2;
        for (int i = 1; i <= n; i ++ ) cout << i << " " << i << " "; cout << '\n';
    }
    return 0;
}