#include <bits/stdc++.h>
using namespace std;

double quick_sort(double a, int n) {
    double res = 1;
    while (n) {
        if (n & 1) res = res * a;
        a *= a; n >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        double r0, c0, p, L, R; cin >> r0 >> c0 >> p >> L >> R;
        
        double res = p * (1 - quick_sort(p, n)) / (1 - p) * c0;
        
        vector<double> r(n + 1); r[0] = r0;
        fill(r.begin() + 1, r.end(), L);

        for ( ; k -- ; ) {
            int x, num; cin >> x >> num;
            r[x] = num;
        }
        double P = 1;
        for (int i = n; i >= 0; i -- ) {
            res -= P * r[i]; P = P * p;
        }
        cout << fixed << setprecision(10) << res + r0 << '\n';
    }
    return 0;
}