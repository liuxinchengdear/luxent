#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (min({a, b, c, d}) == max({a, b, c, d})) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}