#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int y, r; cin >> y >> r;
        cout << min(n, r + y / 2) << endl;
    }
    return 0;
}