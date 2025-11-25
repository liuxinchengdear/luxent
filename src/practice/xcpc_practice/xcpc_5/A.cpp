#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100010;

bool yy[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int st; cin >> st;

        memset(yy, 0, sizeof yy);

        int n; cin >> n;
        for (int i = 0, x; i < n; i ++ ) cin >> x, yy[x] = true;

        int ed; cin >> ed;
        int res = 0;
        for (int i = st; i <= ed; i ++ ) {
            res += !yy[i];
        }
        cout << res << '\n';
    }
    return 0;
}