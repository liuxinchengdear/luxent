#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, y, z; cin >> x >> y >> z;

        if ((y + 1 >> 1 > x) || (y & 1) && !z) { cout << "No\n"; continue; }
        cout << (z > x ? "No\n" : "Yes\n");
    }
    return 0;
}