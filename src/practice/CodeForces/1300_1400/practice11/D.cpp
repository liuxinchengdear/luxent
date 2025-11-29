#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
        int cnt = 0; int tmp = k; k = 1;
        for (; k <= r2; k *= tmp) {
            int l = max(l1, (int)ceil(l2 * 1.0 / k)), r = min(r1, r2 / k);
            cnt += max(0ll, r - l + 1);
        }
        cout << cnt << endl;
    }
    return 0;
}