#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x, y; cin >> n >> x >> y;

        vector<int> a(n + 1);
        for (int i = 1; i < y; i ++ ) a[i] = i & 1 ? -1 : 1;
        for (int i = y; i <= x; i ++ ) a[i] = 1;
        for (int i = x + 1, cnt = 1; i <= n; i ++ , cnt ++ ) a[i] = cnt & 1 ? -1 : 1;
        
        if (y > 1 && a[y - 1] == 1 && x - y + 1 == 2) for (int i = 2; i <= y - 2; i ++ ) a[i] = i & 1 ? 1 : -1;
        a[y - 1] = -1;

        for (int i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
    }
    return 0;
}