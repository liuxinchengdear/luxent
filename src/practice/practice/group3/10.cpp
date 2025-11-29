#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        auto check = [&](int x) -> bool {
            for (int i = 1, cnt = 0; i <= n; i += 2) {
                if (i + 1 > n) return cnt ? false : true;
                int d = a[i + 1] - a[i];
                if (d > x && ++ cnt > 1) return false;
                i -= d > x; 
            }
            return true;
        };

        auto binary_search = [&](int l, int r) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid)) r = mid;
                else l = mid + 1;
            }
            return r;
        };

        if (n == 1) { cout << 1 << endl; continue; }

        cout << binary_search(1, 1e18) << endl;
    }
    return 0;
}