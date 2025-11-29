#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI int _T; cin >> _T; while (_T -- )

struct Frac {
    int a, b;

    Frac() {}
    Frac(int a, int b) : a(a), b(b) {}

    void show() {
        int d = gcd(a, b);
        cout << a / d << '/' << b / d << '\n';
    }

    bool operator >= (const Frac &p) const { return a * p.b >= b * p.a; }
}k, l, r;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        cin >> k.a >> k.b >> l.a >> l.b >> r.a >> r.b;

        Frac tmp(k.a * r.b, k.b * r.a);

        int Y = tmp.a / tmp.b + 1;
        Frac ans(r.a * Y, r.b);
        // if (tmp.a % tmp.b) {
        //     Frac x(k.a, k.b * Y);
        //     if (x >= l) {
        //         Frac now(x.a * (Y + 1), x.b);
        //         if (now >= ans) ans = now;
        //     }
        // }
        ans.show();
    }
    system("pause");
    return 0;
}