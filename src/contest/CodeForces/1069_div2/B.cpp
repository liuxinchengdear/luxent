#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, l, r; cin >> n >> l >> r;

        vector<int> a(n + 1);

        vector<int> tmp{65, 66, 67};
        for (int i = 1, cnt = 0; i <= n; ++ i, ++ cnt) a[i] = tmp[cnt % 3];
    
        if ((r - l + 1) & 1) a[l] = 32 + a[l] - 64, a[r] = 32 + a[r];
        else {
            auto t = r - l + 1;
            if (t % 3 == 1) a[l] = 32 + 64, a[r] = a[r] + 32;
            else if (t % 3 == 2) ;
        }

        for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
    }
    return 0;
}