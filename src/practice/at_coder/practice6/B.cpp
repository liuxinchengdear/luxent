#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), tr(n + 1);

    auto update = [&](int x, int v) -> void {
        while (x <= n) tr[x] += v, x += lowbit(x);
    };

    auto query = [&](int x) -> int {
        int res = 0;
        while (x) res += tr[x], x -= lowbit(x);
        return res;
    };

    for (int i = 1; i <= n; i ++ ) cin >> a[i], update(i, a[i] - a[i - 1]);

    vector<int> res(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int x = query(i);
        auto add = min(x, n - i);
        update(i + 1, 1); update(i + add + 1, -1);
        update(i, -add); update(i + 1, add);
        res[i] = x - add;
    }

    for (int i = 1; i <= n; i ++ ) cout << res[i] << " \n"[i == n];
    return 0;
}