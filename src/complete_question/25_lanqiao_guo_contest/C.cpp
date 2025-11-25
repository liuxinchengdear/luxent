#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

int ex_gcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    int d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        int n, k; cin >> n >> k;
        int pos = k % n + 1;
        // pos + 2x + ny = 1
        int x, y;
        int d = ex_gcd(2, n, x, y);
        if ((1 - pos) % d == 0) cout << (x % n + n) % n << '\n';
        else cout << -1 << '\n';
    }
    cout.flush();
    system("pause");
    return 0;
}