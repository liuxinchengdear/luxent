#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int m; cin >> m;

    vector<vector<int>> num(m + 1, vector<int>(n + 1));
    vector<int> w(m + 1);
    for (int i = 1; i <= m; i ++ ) {
        cin >> w[i];
        for (int j = 1; j <= n; j ++ ) cin >> num[i][j];
    }

    int ans = 1e9, cnt = 0;
    for (int i = 1; i < 1 << m; i ++ ) {
        vector<int> tmp(n + 1); int res = 0;
        int c = 0;
        for (int j = 0; j < m; j ++ ) {
            if (i >> j & 1) {
                for (int k = 1; k <= n; k ++ ) {
                    tmp[k] += num[j + 1][k];
                }
                res += w[j + 1]; c ++ ;
            }
        }
        bool flag = true;
        for (int j =  1; j <= n; j ++ ) if (tmp[j] < a[j]) flag = false;
        if (flag) {
            if (ans > res) ans = res, cnt = c;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}