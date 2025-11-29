#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int mx = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i], mx = max(mx, a[i]);

        int len = 0;
        while (mx) mx >>= 1, ++ len;

        for (int i = 0; i < len; i ++ ) {
            set<int> st; 
            for (int j = 0; j < n; j ++ ) st.insert(a[j] >> i & 1);
            if (st.size() > 1) {cout << (1ll << i + 1) << '\n';break;}
        }
    }
    return 0;
}