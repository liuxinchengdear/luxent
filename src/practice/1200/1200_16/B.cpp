#include <bits/stdc++.h>
using namespace std;

#define int long long

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        map<int, int> mpx;
        for (int i = 0; i < n; i ++ ) {
            int x, t; cin >> x;
            while (x) t = lowbit(x), mpx[t] ++ , x -= t; 
        }

        int tmp = 0;
        for (auto [k, v] : mpx) tmp += (v & 1) * k;

        map<int, int> mx, mn;
        for (int i = 0; i < m; i ++ ) {
            int x, t; cin >> x;
            while (x) {
                t = lowbit(x); x -= t;
                if (n & 1) mx[t] ++ ;
                else mn[t] ++ ;
            }
        }
        int mxx = tmp, mnn = tmp;
        for (auto [k, v] : mx) if ((tmp & k) == 0) mxx += k; 
        for (auto [k, v] : mn) if (tmp & k) mnn -= k;
        cout << mnn << " " << mxx << '\n';
    }
    return 0;
}