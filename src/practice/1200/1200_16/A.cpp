#include <bits/stdc++.h>
using namespace std;

#define int long long

#define equation(l, r) (((l) + (r)) * ((r) - (l) + 1) / 2)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x, y; cin >> n >> x >> y;
        int nx = n / x, ny = n / y, nxy = n * gcd(x, y) / x / y;
        nx -= nxy; ny -= nxy;
        cout << equation(n - nx + 1, n) - equation(1, ny) << '\n';
    }
    return 0;
}