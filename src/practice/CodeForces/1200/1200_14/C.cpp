#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> num(n, vector<int>(n));
        vector<int> a(n);

        for (int i = 0; i < n; i ++ ) {
            auto e = (1 << 30) - 1;
            for (int j = 0; j < n; j ++ ) {
                cin >> num[i][j];
                if (i == j) continue;
                e = e & num[i][j];
            }
            a[i] = e;
        }

        bool flag = true;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (i == j) continue;
                if ((a[i] | a[j]) != num[i][j]) {flag = false; break;}
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
        if (flag) for (int i = 0; i < n; i ++ ) cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}