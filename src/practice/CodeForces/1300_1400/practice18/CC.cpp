#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;

        int w; cin >> w;
        vector<int> a(n * m); 
        for (int i = 0; i < w; i ++ ) cin >> a[i];

        vector<vector<int>> g(n + 2, vector<int>(m + 2));

        for (int i = k; i <= n; i ++ ) {
            for (int j = k; j <= m; j ++ ) {
                g[i + 1][j + 1] ++ ; g[i - k + 1][j - k + 1] ++ ;
                g[i - k + 1][j + 1] -- ; g[i + 1][j - k + 1] -- ;
            }
        }

        vector<int> res;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
                res.push_back(g[i][j]); 
            }
        }

        sort(res.begin(), res.end()); sort(a.begin(), a.end());

        int sum = 0;
        for (int i = 0; i < res.size(); i ++ ) sum += res[i] * a[i];
        cout << sum << endl;
    }
    return 0;
}