#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        long double n, d, h; cin >> n >> d >> h;

        long double ans = d * h / 2;
        int pre = 0;
        map<long double, int> tr;
        for (int i = 0; i < n; i ++ ) {
            int y; cin >> y;
            if (i  && y - pre < h) tr[h + pre - y] ++ ;
            pre = y;
        }
        long double fu = 0;
        for (auto [k, v] : tr) {
            fu += ans / h * k / h * k * v;
        }
        cout << fixed << setprecision(8) << ans * n - fu << '\n';
    }
    return 0;
}