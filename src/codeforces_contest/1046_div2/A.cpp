#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        c -= a; d -= b;
        a > b ? swap(a, b), 1 : 1;
        c > d ? swap(c, d), 1 : 1;
        cout << ((a + 1 >= (b + 1 >> 1)) && (c + 1 >= (d + 1 >> 1)) ? "YES\n" : "NO\n");
    }
    return 0;
}