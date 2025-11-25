#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string a, b; cin >> a >> b;

        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i ++ ) n1 += a[i] != b[i], n2 += a[i] != b[n - 1 - i];

        cout << min(n1 * 2 - n1 % 2, max(2, n2 * 2 - (1 - n2 % 2))) << '\n';
    }
    return 0;
}