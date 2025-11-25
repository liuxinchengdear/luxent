#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 400010;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> pm(N + 1);
    auto Erato = [&] -> void {
        for (int i = 2; i <= N; i ++ ) {
            if (!pm[i].size()) {
                for (int j = i; j <= N; j += i) pm[j].push_back(i);
            }
        }
    };

    Erato();

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        
        bool fg = false;
        unordered_map<int, int> mp; vector<int> a(n), b(n);
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; a[i] = x;
            for (auto e : pm[x]) {
                if ( ++ mp[e] >= 2) fg = true;
            }
        }

        pii mn = {1e9, 1e9};
        for (int i = 0; i < n; i ++ ) {
            cin >> b[i];
            auto &[m1, m2] = mn;
            int x = max(m1, m2), y = min(m1, m2);
            x = min(x, b[i]);
            m1 = x; m2 = y;
        }

        if (n == 1 || fg) { cout << "0\n"; continue; }

        int res = 1e9;
        for (int i = 0; i < n; i ++ ) { auto e = a[i];
            if (fg) break;
            for (auto p : pm[e]) mp[p] -- ;
            for (auto p : pm[e + 1]) {
                if (mp[p]) {
                    fg = true;
                    res = min(res, b[i]);
                }
            }
            for (auto p : pm[e]) mp[p] ++ ;
        }

        if (!fg) res = mn.first + mn.second;

        int mnn = min(mn.first, mn.second);
        vector<int> num;
        for (int i = 0; i < n; i ++ ) {
            if (b[i] == mnn) num.push_back(i);
        }

        vector<int> na = a; sort(na.begin(), na.end());
        for (auto idx : num) {
            auto t = lower_bound(na.begin(), na.end(), a[idx] + 1);
            int ed = t == na.end() ? na.back() * 2 : *t;
            for (auto e : pm[a[idx]]) mp[e] -- ;
            for (int i = a[idx] + 1; i <= ed; i ++ ) {
                for (auto p : pm[i]) {
                    if (mp[p]) res = min(res, b[idx] * (i - a[idx]));
                }
            }
            for (auto e : pm[a[idx]]) mp[e] ++ ;
        }
        
        cout << res << endl;
    }
    return 0;
}