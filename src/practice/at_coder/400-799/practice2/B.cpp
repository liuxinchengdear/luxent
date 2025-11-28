#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        cout << ((m + 1 >> 1) + (m >> 1) * (n - 1)) << endl;
    }
    return 0;
}