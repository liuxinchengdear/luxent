#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int _T; cin >> _T; while (_T -- ) {
        int n, m, L; cin >> n >> m >> L;
        vector<pii> a(n);
        for (int i = 0; i < n; i ++ ) {
            int l, r; cin >> l >> r;
            a[i] = {l, r};
        }

        multiset<int> st;
        bool fg = true;
        int pos = 0, sum = 1, cnt = 0;
        for (int i = 0; i < m; i ++ ) {
            int p, x; cin >> p >> x; 
            while (fg && pos < n && p > a[pos].first) {
                auto [l, r] = a[pos];
                int len = r - l + 1;
                while (st.size() && sum <= len) {
                    sum += *st.rbegin(); st.erase(prev(st.end()));
                    cnt ++ ;
                }
                if (sum <= len) fg = false;
                pos ++ ;
            }
            st.insert(x);
        }

        for ( ;fg && pos < n; pos ++ ) {
            auto [l, r] = a[pos];
            int len = r - l + 1;
            while (st.size() && sum <= len) {
                sum += *st.rbegin(); st.erase(prev(st.end()));
                cnt ++ ;
            }
            if (sum <= len) { fg = false; break; }
        }

        cout << (fg ? cnt : -1) << endl;
    }
    return 0;
}