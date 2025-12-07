#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1), c(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];
        for (int i = 1; i <= n; i ++ ) cin >> c[i];

        int tot = accumulate(a.begin() + 1, a.end(), 0ll), val = (tot + 2) / 3;
        
        vector<int> pa(n + 1), pb(n + 1), pc(n + 1), sa(n + 2), sb(n + 2), sc(n + 2);

        for (int i = 1; i <= n; i ++ ) {
            pa[i] = pa[i - 1] + a[i];
            pb[i] = pb[i - 1] + b[i];
            pc[i] = pc[i - 1] + c[i];
        }
        for (int i = n; i ; i -- ) {
            sa[i] = sa[i + 1] + a[i];
            sb[i] = sb[i + 1] + b[i];
            sc[i] = sc[i + 1] + c[i];
        }

        auto mat = [&](char c, bool fg) -> vector<int>& {
            if (c == 'a') return fg ? pa : sa;
            if (c == 'b') return fg ? pb : sb;
            if (c == 'c') return fg ? pc : sc;
            return a;
        };

        auto eval = [&](string s) -> bool {
            vector<int> &pre = mat(s[0], true), &mid = mat(s[1], true), &suff = mat(s[2], false);
            int i = 1, j = n; 
            int sl = 0, sm = 0, sr = 0;
            i = lower_bound(pre.begin(), pre.end(), val) - pre.begin();
            while (j >= 1 && suff[j] < val) -- j;
            int num = mid[j - 1] - mid[i];
            bool fg = i < j && num >= val;

            if (fg) {
                map<int, pair<int, int>> mp;
                mp[s[0]] = {1, i}; mp[s[1]] = {i + 1, j - 1}; mp[s[2]] = {j, n};
                for (auto [k, v] : mp) {
                    auto [l, r] = v;
                    cout << l << " " << r << " ";
                }
                cout << '\n';
            }
            return fg;
        };

        string s = "abc"; bool fg = false;
        do {
            if (eval(s)) { fg = true; break; }
        } while (next_permutation(s.begin(), s.end()));

        if (fg) continue; 

        cout << "-1\n";
    }
    return 0;
}