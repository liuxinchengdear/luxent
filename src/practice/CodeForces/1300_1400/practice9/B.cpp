#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n, p; cin >> r >> c >> n >> p;

    vector<vector<int>> g(r + 1, vector<int>(c + 1));
    int x, y;
    for (int i = 1; i <= r; i ++ ) {
        for (int j = 1; j <= c; j ++ ) {
            cin >> g[i][j];
            if (g[i][j] == n) x = i, y = j;
        }
    }

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    
}