#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin  >> n >> k;

        vector<int> a(n + 1);
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; a[x] ++ ;
        }

        vector<int> pre(n + 1), suff(n + 2);
        for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];
        for (int i = n; i ; i -- ) suff[i] = suff[i + 1] + a[i];

        int res = 1;
        for (int g = 1; g <= n; g ++ ) {
            int num = a[g];
            if (g << 1 <= n) num += a[g << 1];
            if (g * 3 <= n) num += a[g * 3];
            if (g << 2 <= n) num += suff[g << 2];
            if (n - num <= k) res = g;
        }

        cout << res << endl;
    }
    return 0;
    
}