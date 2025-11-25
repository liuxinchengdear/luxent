#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, y, X, Y; cin >> x >> y >> X >> Y;

        x = abs(x - X); y = abs(y - Y);
        int res = max(x >> 1, y >> 1);
        x %= 3; y %= 3;

        if (x == 0 && y == 0) {cout << res << '\n'; continue;}
        if (!x && y || x && !y) res += 2;
        else res += 1;
        cout << res << '\n';
    }
    return 0;
}