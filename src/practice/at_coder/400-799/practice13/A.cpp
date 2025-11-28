#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1, x; i <= n; i ++ ) {
        cin >> x; a[x] = i;
    }

    vector<int> mn(n + 1), mx(n + 1);
    vector<int> q(n + 1);

    // 单调队列
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ ) {
        // 维护长度
        if (hh <= tt && q[tt] - q[hh] + 1 >= k) hh ++ ;
        // 维护队列
        while (hh <= tt && a[i] < a[q[tt]]) tt -- ;
        q[ ++ tt] = i;
        if (i >= k) mn[i] = a[q[hh]];
    }

    hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ ) {
        // 维护长度
        if (hh <= tt && q[tt] - q[hh] + 1 >= k) hh ++ ;
        // 维护队列
        while (hh <= tt && a[i] > a[q[tt]]) tt -- ;
        q[ ++ tt] = i;
        if (i >= k) mx[i] = a[q[hh]];
    }
    
    int res = 1e9;
    for (int i = k; i <= n; i ++ ) res = min(res, mx[i] - mn[i]);
    cout << res << endl;

    return 0;
}