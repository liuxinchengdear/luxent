#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int b, c, d; cin >> b >> c >> d;

        int a = c ^ d;
        if ((a | b) - (a & c) == d) cout << a << endl;
        else cout << -1 << endl;
    }
    return 0;
}