#include <bits/stdc++.h>
using namespace std;

#define int long long

// i 为奇数， j 为奇数  ->  j - i
// i 为奇数， j 为偶数  ->  2 * a[j] - 2 * a[i] + j - i
// i 为偶数， j 为奇数  ->  -2 * a[j] + 2 * a[i] + j - i
// i 为偶数， j 为偶数  ->  j - i

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); int f = 0;
        vector<int> odd(n + 1), even(n + 1);

        odd.front() = even.front() = -2e9;
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            if (i & 1) {
                odd[i] = max(odd[i - 1], -2 * a[i] - i);
                even[i] = even[i - 1];
            }
            else {
                even[i] = max(even[i - 1], 2 * a[i] - i);
                odd[i] = odd[i - 1];
            }
            f += (i & 1 ? 1 : -1) * a[i];
        }

        int res = 0;
        for (int j = 1; j <= n; ++ j) {
            if (j & 1) {
                res = max(res, max(j - 1, j == 1 ? 0ll : j - 2 * a[j] + even[j - 1]));
            }
            else {
                res = max(res, max(j - 2, j + 2 * a[j] + odd[j - 1]));
            }
        }
        cout << f + res << endl;
    }
    return 0;
}