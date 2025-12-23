#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int k, x; cin >> k >> x;
        cout << x * k + 1 << endl;
    }
    return 0;
}