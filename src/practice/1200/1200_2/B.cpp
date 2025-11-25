#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int w, h, a, b; cin >> w >> h >> a >> b;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        int r = abs(x1 - x2), c = abs(y1 - y2);
        bool flag = false;

        if (r >= a) (r - a) % a ? false : flag = true;
        if (c >= b) (c - b) % b ? false : flag = true;

        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}