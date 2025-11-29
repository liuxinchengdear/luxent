#include <bits/stdc++.h>
using namespace std;

#define int long long

// 消去一个变量, 容斥原理
// 换另一个角度

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int m, k, a1, ak; cin >> m >> k >> a1 >> ak;
        
        int sub = min(ak, m / k); ak -= sub; m -= sub * k;
        int sub1 = min(a1, m); a1 -= sub1; m -= sub1;
        if (!m) cout << "0\n";
        else {
            int ck = m / k, c1 = m % k;
            if (c1 && sub1 + c1 >= k) ck ++ , c1 = 0;
            cout << ck + c1 << '\n';
        }
    }
    return 0;
}