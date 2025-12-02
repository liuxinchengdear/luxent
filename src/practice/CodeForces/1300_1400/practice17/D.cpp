#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        auto fun = [&](int x) -> int {
            return (k + k + x - 1) * x / 2 - (k + x + k + n - 1) * (n - x) / 2;
        };

        auto binary_search = [&](int l, int r) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (fun(mid) >= 0) r = mid;
                else l = mid + 1;
            }
            return r;
        };

        auto t = binary_search(1, n + 1);

        cout << min(abs(fun(t)), abs(fun(t - 1))) << endl;
    }
    return 0;
}