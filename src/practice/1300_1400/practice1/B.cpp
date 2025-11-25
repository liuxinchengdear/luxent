#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
        if (a == c && b == d) {cout << "1\n"; continue;}

        int ans = 0;
        if (a == c) {
            if (b < d) ans = d;
            else ans = n - d;
        }
        else if (b == d) {
            if (a < c) ans = c;
            else ans = n - c;
        }
        else {
            if (a < c && b < d) ans = max(c, d);
            else if (a < c && b > d) ans = max(c, n - d);
            else if (a > c && b < d) ans = max(n - c, d);
            else if (a > c && b > d) ans = max(n - c, n - d);
        }
        cout << ans << endl;
    }
    return 0;
}