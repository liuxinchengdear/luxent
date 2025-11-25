#include <bits/stdc++.h>
using namespace std;

ostream& operator << (ostream &os, const unordered_set<int> &X) {
    for (auto e : X) os << e << " "; return os;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> tmp(n); iota(tmp.begin(), tmp.end(), 1);

        unordered_set<int> arr(tmp.begin(), tmp.end());

        vector<vector<int>> a(n + 1);
        int mx = 0;
        for (int u = 1; u <= n; u ++ ) {
            cout  << "? " << u << " " << arr.size() << " " << arr << endl;
            int x; cin >> x; a[x].push_back(u);
            mx = max(mx, x);
        }

        int st = a[mx].front();
        vector<int> ans{st};
        for  (auto pat = mx - 1; pat ; pat -- ) {
            for (auto e : a[pat]) arr.erase(e);
            for (auto e : a[pat]) {
                arr.insert(e);
                cout  << "? " << st << " " << arr.size() << " " << arr << endl;
                int x; cin >> x; if (x == mx) {ans.push_back(e); break;}
                arr.erase(e);
            }
        }
        cout << "! " << ans.size() << " ";
        for (auto e : ans) cout << e << " "; cout << endl;
    }
    return 0;
}