#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        using ll = long long;
        int n, k; cin >> n >> k;

        map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x;
            mp[x] ++ ;
        }

        int st = 0, ed = -1e9;
        int res = 0;
        for (auto [num, cnt] : mp) {
            st = max(ed + 1, num - k); ed = min(num + k, cnt + st - 1);
            res += ed - st + 1;
        }
        cout << res << '\n';
    }
    return 0;
}