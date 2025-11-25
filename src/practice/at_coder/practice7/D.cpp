#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200010;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int hh = 0, tt = -1;
    int q; cin >> q;
    while (q -- ) {
        int op, x; cin >> op;
        if (op == 1) { ++ tt; continue; }
        if (op == 2) {
            cin >> x; 
            if (tt < hh) continue;
            a[hh] += x; a[tt + 1] -= x;
            continue;
        }
        cin >> x;
        int cnt = 0, sum = 0;
        for (; hh <= tt; cnt ++ , hh ++ ) {
            sum += a[hh];
            if (sum < x) break;
        } 
        if (hh > tt) sum += a[hh];
        a[hh] = sum;
        cout << cnt << '\n';
    }
    return 0;
}