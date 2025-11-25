#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fun(a, b) ((a) * (a) + (b) * (b))

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<pii> pt(n);
        for (int i = 0; i < n; i ++ ) {
            int a, b; cin >> a >> b;
            pt[i] = {a, b};
        }
        int a, b, c, d; cin >> a >> b >> c >> d;
        int dis = 3000'000'000'000'000'000;
        for (int i = 0; i < n; i ++ ) {
            auto [x, y] = pt[i];
            dis = min(dis, fun(x - c, y - d));
        }

        int ans = fun(a - c, b - d);
        cout << (ans < dis ? "YES\n" : "NO\n");
    }
    return 0;
}