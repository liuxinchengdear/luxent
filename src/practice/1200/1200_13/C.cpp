#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), pre(n + 1), odd(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i], odd[i] = odd[i - 1] + (a[i] & 1);

        for (int i = 1; i <= n; i ++ ) {
            if (i == 1) {cout << pre[i] << " \n"[i == n]; continue;}
            int num = odd[i] / 3 + (odd[i] % 3 == 1);
            cout << pre[i] - num << " \n"[i == n];
        }
    }
    return 0;
}