#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> a(n + 1);
        vector<int> tmp(2 * n + 1);

        for (int i = 1; i <= n << 1; ++ i) {
            int x; cin >> x; a[x].push_back(i); tmp[i] = x;
        }

        int cnt = 0;
        vector<bool> st(n + 1); 
        for (int i = 1; i < n << 1; ++ i) {
            auto x = tmp[i], y = tmp[i + 1];
            if (st[x] || st[y]) continue; st[x] = true;
            if (abs(a[x].front() - a[y].front()) == 1 && abs(a[x].back() - a[y].back()) == 1 && abs(a[x].front() - a[x].back()) != 1 && abs(a[y].front() - a[y].back()) != 1) {
                cnt ++ ;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}