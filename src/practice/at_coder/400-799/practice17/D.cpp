#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<string> g(n + 1);

    for (int i = 1; i <= n; i ++ ) cin >> g[i], g[i] = " " + g[i];

    vector<int> row(n + 1), col(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            row[i] += g[i][j] == 'o';
            col[j] += g[i][j] == 'o';
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (g[i][j] == 'o' && row[i] > 1 && col[j] > 1) res += (row[i] - 1) * (col[j] - 1);
        }
    }
    cout << res << endl;
    return 0;
}