#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n << 1; i ++ ) {
            int x; cin >> x; mp[x] ++ ;
        }

        int cnt = 0, nt = 0, t = 0;
        for (auto [k, v] : mp) {
            if (v & 1) {
                t ++ ; cnt ++ ;
            }
            else {
                if (v % 4 == 0) nt ++ ;
                cnt += 2;
            }
        }

        if (nt & 1 && !t) cnt -= 2;
        
        cout << cnt << endl;
    }
    return 0;
}