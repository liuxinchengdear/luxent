#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<pii> tmp(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> tmp[i].first;
        for (int i = 1; i <= n; i ++ ) cin >> tmp[i].second;

        map<pii, int> mp;
        vector<int> a(n + 1); int cnt = 0;
        vector<vector<int>> num(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            auto &[l, r] = tmp[i]; tmp[i] = {min(l, r), max(l, r)};

            if (mp.count(tmp[i])) a[i] = mp[tmp[i]];
            else a[i] = mp[tmp[i]] = ++ cnt;

            num[a[i]].push_back(i);
        }

        bool fg = true; vector<pii> ans;
        for (int i = 1, j = n; i < j; i ++ , j -- ) {
            if (a[i] != a[j]) {
                if (num[a[i]].size() != 2 && num[a[j]].size() != 2) { fg = false; break; }
                
                if (num[a[i]].size() == 2) {
                    auto l = num[a[i]].front(), r = num[a[i]].back();
                    if (l > r) swap(l, r);
                    if (num[a[j]].front() == j) num[a[j]].front() = r;
                    else num[a[j]].back() = r;
                    swap(a[r], a[j]); ans.push_back({r, j});
                }
                else {
                    auto l = num[a[j]].front(), r = num[a[j]].back();
                    if (l > r) swap(l, r);
                    num[a[i]].front() = l;
                    swap(a[i], a[l]); ans.push_back({i, l});
                }
            }
        }

        if (!fg) { cout << "-1\n"; continue; }
        cout << ans.size() << endl;
        for (auto [l, r] : ans) {
            cout << l << " " << r << endl;
        }
    }
    return 0;
}