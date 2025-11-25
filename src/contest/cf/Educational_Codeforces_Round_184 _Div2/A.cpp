#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, a; cin >> n >> a;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> v[i];

        sort(v.begin(), v.end());

        int n1 = 0, n2 = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (abs(v[i] - a) > abs(v[i] - a + 1)) n1 ++ ;
            if (abs(v[i] - a) > abs(v[i] - a - 1)) n2 ++ ;
        }
        cout << (n1 > n2 ? a - 1 : a + 1) << endl;
    }
    return 0;
}