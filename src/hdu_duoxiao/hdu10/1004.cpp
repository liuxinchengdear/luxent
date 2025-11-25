#include <bits/stdc++.h>
using namespace std;

const int N = 1000010, mod = 998244353;

int n, m;
int p[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        cin >> n >> m;
        memset(p, 0, sizeof p);
        memset(t, 0, sizeof t);
        auto offset = n * m;
        p[offset] = 1;
        for (int i = 0; i < n; i ++ ) {
            int res = 0;
            for (int j = -m, x; j <= m; j ++ ) {
                cin >> x;
                for (int k = i * -m; k <= i * m; k ++ ) {
                    if (k >= 0 && j + k >= 0) {
                        long long num = 1LL * p[k + offset] * x % mod;
                        t[k + j + offset] = (t[k + j + offset] + num) % mod;
                        res = (res + num) % mod;
                    }
                }
            }
            memcpy(p, t, sizeof t);
            memset(t, 0, sizeof t);
            cout << res << " \n"[i == n - 1];
        }
    }
    return 0;
}