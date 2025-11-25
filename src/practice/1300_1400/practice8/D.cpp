#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 100;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pm;

    auto eular = [&] -> void {
        vector<bool> st(N + 1);
        for (int i = 2; i <= N; i ++ ) {
            if (!st[i]) pm.push_back(i);
            for (int j = 0; pm[j] <= N / i; j ++ ) {
                st[i * pm[j]] = true;
                if (i % pm[j] == 0) break;
            }
        }
    };

    eular();

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        int res = 0;
        for (int a = 1; a <= n / 2; a ++ ) {
            int d = n / a;
            auto p = lower_bound(pm.begin(), pm.end(), d);
            if (*p * a > n) p = prev(p);
            res += p - pm.begin() + 1;
        }
        cout << res << endl;
    }
    return 0;
}