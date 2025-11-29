#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> a(2 * n + 1);
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i ++ ) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) a[r[i]].push_back(i);
        }
        string s = string(n, 0x31);
        vector<int> b(2 * n + 1);
        for (int i = 1; i <= 2 * n; i ++ ) {
            b[i] = b[i - 1] + (a[i].size() > 0);
            if (a[i].size() > 1) {
                for (auto e : a[i]) s[e] = 0x30;
            }
        }
        for (int i = 0; i < n; i ++ ) 
            if (r[i] - l[i] + 1 > 1 && r[i] - l[i] + 1 == b[r[i]] - b[l[i] - 1]) 
                s[i] = 0x30;
        cout << s << '\n';
    }
    return 0;
}