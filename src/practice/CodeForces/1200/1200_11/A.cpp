#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1), mx(n + 1); mx[0] = -1;
        
        for (int i = 1; i <= n; i ++ ) cin >> a[i], mx[i] = max(mx[i - 1], a[i]);
    
        auto p = lower_bound(mx.begin(), mx.end(), a[k] + 1) - mx.begin();

        if (p >= k) cout << p - 2 << '\n';
        else {
            swap(a[p], a[k]);
            for (int i = 1; i <= n; i ++ ) mx[i] = max(mx[i - 1], a[i]);
            auto pp = lower_bound(mx.begin(), mx.end(), a[p] + 1) - mx.begin();

            cout << max(p == 1 ? pp - p - 1 : pp - p, p - 2) << '\n';
        }
    }
    return 0;
}