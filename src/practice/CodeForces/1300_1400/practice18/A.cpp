#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<array<int, 2>> g(n + 1);
        for (int i = 0; i < n; i ++ ) {
            int x, y; cin >> x >> y; g[x][y] = 1;
        }

        int sum = 0;
        for (int i = 0; i <= n; i ++ ) {
            if (g[i][0] && g[i][1]) {
                sum += n - 2;
            }
        }

        for (int i = 1; i < n; i ++ ) {
            for (int j = 0; j <= 1; j ++ ) {
                sum += g[i][j] && g[i - 1][1 - j] && g[i + 1][1 - j];
            }
        }

        cout << sum << endl;
    }
    return 0;
}