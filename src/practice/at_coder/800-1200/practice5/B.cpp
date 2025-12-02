#include <bits/stdc++.h>
using namespace std;

#define int long long

// dfs

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    vector<vector<int>> a(n + 1);

    for (int i = 1; i <= m; i ++ ) {
        int k; cin >> k;
        for (int j = 0; j < k; j ++ ) {
            int x; cin >> x; a[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {

        }
    }
    return 0;
}