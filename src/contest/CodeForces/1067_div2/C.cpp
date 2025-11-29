#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        int mx = -1e9; 
        for (int i = 1, sum = 0; i <= n; i ++ ) {
            sum += a[i]; mx = max(mx, sum);
            if (sum < 0) sum = 0;
        }
        if (k % 2 == 0) { cout << mx << endl; continue; }

        vector<pii> res;

        for (int i = 1; i <= n; i ++ ) {
            int l = i, r = i, sum = 0;
            while (i <= n && a[i] < 0) sum += a[i ++ ];
            r = i - 1;
            if (l <= r) res.push_back({l, r});
        }
    }
    return 0;
}