#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> operator - (const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i ++ ) c[i] = a[i] - b[i];
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;
        a = " " + a; b = " " + b;
        vector<vector<int>> prea(n + 1, vector<int>(26)), preb(n + 1, vector<int>(26));
        for (int i = 1; i <= n; i ++ ) {
            prea[i] = prea[i - 1]; preb[i] = preb[i - 1];
            prea[i][a[i] - 0x61] ++ ; preb[i][b[i] - 0x61] ++ ;
        }
        
        for ( ; q -- ; ) {
            int l, r; cin >> l >> r;
            vector<int> tmp = (prea[r] - prea[l - 1]) - (preb[r] - preb[l - 1]);
            transform(tmp.begin(), tmp.end(), tmp.begin(), [](int num) {
                return abs(num);
            });
            cout << (accumulate(tmp.begin(), tmp.end(), 0) >> 1) << '\n';
        }
    }
    return 0;
}