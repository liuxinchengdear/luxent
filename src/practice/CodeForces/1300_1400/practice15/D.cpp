#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; mp[x] ++ ;
        }

        int s = -1, res = 0, tmp = 0, pre = -1;
        for (auto [key, v] : mp) {
            if (s == -1 || pre + 1 != key) s = pre = key, tmp = v, res = max(res, tmp);
            else {
                if (key - s >= k) tmp += v - mp[s ++ ];
                else tmp += v;
                pre = key; res = max(res, tmp);
            }
        }

        cout << res << endl;
    }
    return 0;
}