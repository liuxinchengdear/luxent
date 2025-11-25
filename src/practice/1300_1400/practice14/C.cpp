#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
 
        int l = 2, r = n - 1;
        while (l < r) {
            if (a[l] == a[l - 1] || a[r] == a[r + 1]) swap(a[l], a[r]);
            l ++ ; r -- ;
        }

        int res = 0;
        for (int i = 1; i + 1 <= n; i ++ ) res += a[i] == a[i + 1];
        cout << res << endl;
    }
    return 0;
}