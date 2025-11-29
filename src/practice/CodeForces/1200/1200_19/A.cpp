#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        sort(a.begin() + 1, a.end());

        auto check = [&]() -> int {
            for (int i = 1; i <= n; i ++ ) {
                int right = i, lies = n - i;
                if (a[i] <= lies) {
                    if (i + 1 <= n) {
                        if (a[i + 1] > lies) return lies;
                    }
                    else return lies;
                }
            }
            return -1;
        };

        cout << check() << '\n';
        
    }
    return 0;
}