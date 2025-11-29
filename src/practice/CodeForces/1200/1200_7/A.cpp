#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i];

        string s; cin >> s; s = " " + s;

        int res = 0;
        int i = 1, j = n;
        while (i < j) {
            while (i <= n && s[i] == 'R') i ++ ;
            while (j >= 1 && s[j] == 'L') j -- ;
            if (i < j) res += pre[j] - pre[i - 1];
            i ++ , j -- ;
        }
        cout << res << '\n';
    }
    return 0;
}