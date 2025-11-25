#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<int> vi(n);
        for (int i = 0; i < n; i ++ ) {
            int w, t; cin >> w >> t;
            vi[i] = k - w + t;
        }
        sort(vi.begin(), vi.end());
        
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res + 1, vi[i]);
        }
        cout << res << '\n';
    }
    return 0;
}