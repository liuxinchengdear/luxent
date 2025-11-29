#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &e : a) cin >> e;
        sort(a.begin(), a.end());

        vector<int> stk;
        for (int i = 0; i < n; i ++ ) {
            if (!i) {stk.push_back(a[i]);continue;}

            auto p = lower_bound(stk.begin(), stk.end(), a[i]);
            if (p != stk.begin() && *prev(p) == a[i] - 1) *prev(p) = a[i];
            else stk.push_back(a[i]);
        }

        cout << stk.size() << '\n';
    }
    return 0;
}