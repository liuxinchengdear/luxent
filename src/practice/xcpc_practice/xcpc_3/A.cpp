/*

线性丢番图方程：ax + by = c

B * 1000 + C * 2500 = y

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int ext_gcd(int a, int b, int &x, int &y) {
    if (!b) {x = 1; y = 0; return a;}
    int d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y; cin >> x >> y;
    int A, B, C, d = ext_gcd(1000, 2500, B, C);
    if (y % d == 0) {
        B *= y / d, C *= y / d;
        int t = (B % 5 + 5) % 5;
        C = C - (t - B) / 5 * 2;
        B = t;
        A = x - (B + C);
        if (B + C > x) cout << "-1\n";
        else cout << A << " " << B << " " << C << '\n';
    }
    else cout << "-1\n";
    return 0;
}