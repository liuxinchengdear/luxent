#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x; cin >> n >> x;
        vector<int> a(n + 1); int mx = 0;
        for (int i = 1; i <= n; i ++ ) cin >> a[i], mx = max(mx, a[i]);

        int sum = accumulate(a.begin(), a.end(), 0ll);
        
        cout << max(mx, (int)ceil(sum * 1.0 / x)) << endl;
    }
    return 0;
}