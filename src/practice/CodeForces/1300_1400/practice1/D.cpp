#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        set<int> st;
        for (int i = 0; i < m; i ++ ) {
            int x; cin >> x; st.insert(x);
        }
        int cur = 1;
        for (auto c : s) {
            cur ++ ;
            if (c == 0x42) {
                while (st.count(cur)) cur ++ ;
            }
            st.insert(cur);
            if (c == 0x42) {
                while (st.count(cur)) cur ++ ;
            }
        }
        cout << st.size() << endl;
        for (auto &e : st) cout << e << " "; cout << endl;
    }
    return 0;
}