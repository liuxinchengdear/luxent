#include <bits/stdc++.h>
using namespace std;

#define int long long


// f(n) = f(s) * f(b)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int s, l, r; cin >> s >> l >> r;

        cout << r - l + 1 << endl;
    }
    return 0;
}