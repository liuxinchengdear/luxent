#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        pii ans = {1, 1}; int mx = 0;
        for (int i = 1; i <= n; i ++ ) {
            int cnt = 0;
            for (int j = i + 1; j <= n; j ++ ) {
                if (a[i] > a[j] && ++ cnt > mx) mx = cnt, ans = {i, j};
                if (a[i] < a[j]) cnt -- ;
            }
        }

        auto [l, r] = ans;
        cout << l << " " << r << endl;
    }
    return 0;
}