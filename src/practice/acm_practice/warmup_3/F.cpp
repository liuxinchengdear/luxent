#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        vector<int> pre1(n + 1), suf0(n + 2);

        for (int i = 1; i <= n; i ++ ) pre1[i] = pre1[i - 1] + (s[i] != 0x30);
        for (int i = n; i; i -- ) suf0[i] = suf0[i + 1] + (s[i] != 0x31);

        int  res = 0;
        for (int i = 1; i <= n; i ++ ) if (s[i] == 0x31) res += suf0[i + 1];

        int ans = res;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i] == '?') {
                res += suf0[i + 1];
                res -= pre1[i - 1];
                ans = max(ans, res);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}