#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100010;

int n, m;
int w[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    cin >> m;
    auto t = (int)ceil(sqrt(n));
    for (int op, a, b; m -- ; ) {
        cin >> op;
        if (op == 1) {
            cin >> a;
            int res = 1e9;
            for (int i = max(1LL, a - t); i <= min(n, a + t); i ++ ) {
                res = min(res, w[i] + (int)pow(abs(a - i), 2));
            }
            cout << res << '\n';
        }
        else cin >> a >> b, w[a] = min(w[a], b);
    }
    
    return 0;
}