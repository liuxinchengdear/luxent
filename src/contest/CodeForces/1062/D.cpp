#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n; 
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        int res = 2;
        while (true) {
            int d = 1e18;
            for (int i = 0; i < n; i ++ ) {
                d = min(d, gcd(a[i], res));
                if (d == 1) break;
            }
            if (d == 1) break;
            res ++ ;
        }
        cout << res << endl;
    }
    return 0;
}