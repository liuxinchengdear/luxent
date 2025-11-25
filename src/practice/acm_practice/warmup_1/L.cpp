#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto t = 1533;

    int k;

    auto check = [&k](__int128 x) -> bool {
        __int128 sum = 0;
        for (__int128 i = 4; i <= x; ) {
            sum += x / i - x / (25 * i);
            i *= 100;
        }
        return x - sum >= k;
    };

    int _T; cin >> _T; while (_T -- ) {
        cin >> k; k += t;

        int l = 0, r = 2e18;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        cout << l << '\n';
    }
    return 0;
}