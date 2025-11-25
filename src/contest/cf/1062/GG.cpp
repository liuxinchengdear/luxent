#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        using pii = pair<int, int>;

        vector<pii> a(n); vector<int> c(n);
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; a[i] = {x, i};
        }
        for (int i = 0; i < n; i ++ ) cin >> c[i];

        sort(a.begin(), a.end());

        for (int i = 1; i <= n; i ++ ) {
        }
    }
}