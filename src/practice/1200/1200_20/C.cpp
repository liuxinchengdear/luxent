#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int cnt = a;
        if (!a) {cout << "1\n"; continue;}

        if (b > c) swap(b, c);
        auto pro = b / a;
        b -= pro * a; c -= pro * a; cnt += 1ll * a * pro * 2;
        cnt += 1ll * b * 2; c -= b; b = 0; 
        cnt += min(a + 1, c + d);
        cout << cnt << '\n';
    }
    return 0;
}