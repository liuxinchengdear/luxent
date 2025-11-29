#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n;cin >> n;

        vector<vector<int>> a(n + 1); bool fg = true;
        for (int i = 1; i <= n; i ++ ) {
            int x; cin >> x;
            a[x].push_back(i); 
            if (fg && a[x].size() > 1) fg = false;
        }

        if (fg) {
            cout << "? " << a[1].back() << " " << a[n].back() << endl;
            int t1; cin >> t1;
            cout << "? " << a[n].back() << " " << a[1].back() << endl;
            int t2; cin >> t2;
            if (t1 == t2 && t1 >= n - 1) cout << "! B" << endl;
            else cout << "! A" << endl; continue;
        }
        int f = 1;
        while (a[f].size()) f ++ ;
        cout << "? " << f << " " << (f == n ? f - 1 : f + 1) << endl;
        int t1; cin >> t1; 
        cout << (t1 ? "! B" : "! A") << endl;
    }
    return 0;
}