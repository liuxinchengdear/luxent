#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;

        auto t = min(n - 1 + m / n, m);
        
        if (k == 1) cout << "1\n";
        else if (k == 2) cout << t << '\n';
        else if (k == 3) cout << max(0ll, m - t) << '\n';
        else cout << "0\n";
    }
    return 0;
}