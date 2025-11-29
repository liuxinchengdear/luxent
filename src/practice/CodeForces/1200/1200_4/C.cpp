#include <bits/stdc++.h>
using namespace std;

#define int long long

int bi_se(int x) {
    int l = 0, r = 100010;
    while (l < r) {
        int mid = l + r >> 1;
        if (mid * (mid + 1) / 2 < x) l = mid + 1;
        else r = mid;
    }
    if (l * (l + 1) / 2 > x) l -- ;
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b; cin >> a >> b;
        cout << bi_se(a + b) << '\n';
    }
    return 0;
}