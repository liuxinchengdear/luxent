#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int mx = 0, mn = 0;
    vector<pii> a(n);
    for (int i = 0; i < n; i ++ ) {
        int l, r; cin >> l >> r;
        mx += r, mn += l;
        a[i] = {l, r};
    }

    bool fg = 0 >= mn && 0 <= mx;

    cout << (fg ? "Yes\n" : "No\n");
    if (fg) {
        int df = 0 - mn;
        for (int i = 0; i < n; i ++ ) {
            auto [l, r] = a[i];
            int num = min(r, l + df); df -= num - l;
            cout << num << " \n"[i == n - 1];
        }
    }
    return 0;
}