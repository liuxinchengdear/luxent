#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b; cin >> a >> b;
        for (int d = gcd(a, b); d > 1; ) {
            b /= d; d = gcd(a, b);
        }
        cout << (b == 1 ? -1 : b) << '\n';
    }
    return 0;
}