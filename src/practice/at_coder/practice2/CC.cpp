#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        int sum = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];

        multiset<int> st; 
        for (int i = 0, x; i < n; i ++ ) cin >> x, st.insert(x), sum += x;

        int cnt = 0;
        for (int i = 1; i <= n; i ++ ) {
            auto p = st.lower_bound(m - a[i]);
            p == st.end() ? p = st.begin(), 1 : cnt += 1;
            st.erase(p);
        }

        cout << sum - 1ll * cnt * m << '\n';
    }
    return 0;
}