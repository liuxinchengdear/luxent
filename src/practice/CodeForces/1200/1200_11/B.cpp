#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + (s[i] == 0x31);

        int res = 0;
        double num = 1e9;
        for (int i = 0; i <= n; i ++ ) {
            if (i) {
                int c0 = i - pre[i], c1 = pre[n] - pre[i];
                if (c0 >= i + 1 >> 1 && c1 >= n - i + 1 >> 1 && abs(n / 2.0 - i) < num) res = i, num = abs(n / 2.0 - i);
            }
            else {
                if (pre[n] >= n + 1 >> 1) res = 0, num = n / 2.0;
            }
        }

        cout << res << '\n';
    }
    return 0;
}