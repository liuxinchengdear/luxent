#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 这种题应该怎么思考?
    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        vector<string> a(n), b(n), c(n, string(m, 0x30));

        for (int i = 0; i < n; i ++ ) cin >> a[i];
        for (int i = 0; i < n; i ++ ) cin >> b[i];

        for (int i = 0; i < n; i ++ ) for (int j = 0; j < m; j ++ ) 
        c[i][j] = (b[i][j] - a[i][j] + 3) % 3;

        bool flag = true;
        for (int x1 = 0; x1 < n - 1; x1 ++ ) {
            if (!flag) break;
            for (int y1 = 0; y1 < m; y1 ++ ) {
                if (c[x1][y1]) {
                    int x2 = x1 + 1, y2 = y1 + 1;
                    while (y2 < m && !c[x1][y2]) y2 ++ ;
                    if (y2 >= m) {flag = false; break;}

                    if (c[x1][y1] == 1) {
                        c[x1][y1] = (c[x1][y1] + 2) % 3;
                        c[x2][y2] = (c[x2][y2] + 2) % 3;
                        c[x1][y2] = (c[x1][y2] + 1) % 3;
                        c[x2][y1] = (c[x2][y1] + 1) % 3;
                    }
                    else {
                        c[x1][y1] = (c[x1][y1] + 1) % 3;
                        c[x2][y2] = (c[x2][y2] + 1) % 3;
                        c[x1][y2] = (c[x1][y2] + 2) % 3;
                        c[x2][y1] = (c[x2][y1] + 2) % 3;
                    }
                }
            }
        }

        for (int i = 0; i < m; i ++ ) if (c[n - 1][i]) {flag = false; break;}

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}