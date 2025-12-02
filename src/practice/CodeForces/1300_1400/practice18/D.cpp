#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p{ 1 };
    for (int i = 1; p.back() < 2e5 + 7; i ++ ) {
        p.push_back(p.back() * 3);
    }

    vector<int> a(2e5 + 5), pre(2e5 + 5);
    for (int i = 1; i <= 200000; i ++ ) {
        auto t = lower_bound(p.begin(), p.end(), i + 1) - p.begin();
        a[i] = t;
    }

    for (int i = 1; i <= 200000; i ++ ) pre[i] = pre[i - 1] + a[i];

    int _T; cin >> _T; while (_T -- ) {
        int l, r; cin >> l >> r;

        cout << pre[r] - pre[l - 1] + a[l] << endl;
    }
    return 0;
}