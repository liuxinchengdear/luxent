#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int i = 1, j = n;
        int mx = n, mn = 1;

        auto check = [&]() -> bool {
            return a[i] != mx && a[i] != mn && a[j] != mx && a[j] != mn && i < j;
        };

        while (i < j) {
            while (i < j && a[i] == mx) i ++ , mx -- ;
            while (i < j && a[i] == mn) i ++ , mn ++ ;
            while (i < j && a[j] == mx) j -- , mx -- ;
            while (i < j && a[j] == mn) j -- , mn ++ ;

            if (check()) {cout << i << " " << j << '\n'; break;}
        }
        if (i >= j) cout << "-1\n";
    }
    return 0;
}