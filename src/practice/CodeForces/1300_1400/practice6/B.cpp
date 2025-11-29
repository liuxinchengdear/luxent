#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> g(n, vector<int>(n));

        int num = n * n;
        
        auto path = [&](int de) -> void {
            for (int i = de; i < n - de; i ++ ) g[de][i] = -- num;
            for (int i = de + 1; i < n - de; i ++ ) g[i][n - 1 - de] = -- num;
            for (int i = n - de - 2; i >= de; i -- ) g[n - 1 - de][i] = -- num;
            for (int i = n - de - 2; i >= de + 1; i -- ) g[i][de] = -- num;
        };

        for (int de = 0; de < n >> 1; de ++ ) path(de);
        for (auto E : g) {
            for (int i = 0; i < n; i ++ ) cout << E[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}