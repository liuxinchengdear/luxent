#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = pow(12, 2); i <= pow(13, 2); i ++ ) cout << i << ": " << sqrtl(i) << endl;
    exit(0);

    int _T; cin >> _T; while (_T -- ) {
        long long k; cin >> k;
        cout << k + int(sqrtl(k) + 0.5) << '\n';
    }
    return 0;
}