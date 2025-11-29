#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0, x; i < n; i ++ ) cin >> x, mp[x] ++ ;

        int num = 0, res = 0;
        for (auto [key, val] : mp) {
            if (val > 1) res += val * (val - 1) / 2 * num;
            if (val > 2) res += val * (val - 1) / 2 * (val - 2) / 3;
            num += val;
        }
        cout << res << '\n';
    }
    return 0;
}