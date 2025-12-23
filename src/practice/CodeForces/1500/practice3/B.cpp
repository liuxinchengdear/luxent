#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        unordered_map<int, int> mp;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i], mp[a[i]] ++ ;

        int mx;
        for (int i = 0; ; ++ i) if (mp[i] < k) { mx = i; break; }

        auto check = [&](int x) -> bool {
            unordered_set<int> st; int num = 0;
            for (int i = 1; i <= n; ++ i) {
                if (a[i] <= x) st.insert(a[i]);
                if (st.size() == x + 1) {
                    st.clear();
                    if (++ num == k) return true;
                }
            }
            return false;
        };

        auto binary_search = [&](int l, int r) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid)) l = mid + 1;
                else r = mid;
            }

            return r;
        };

        cout << binary_search(0, mx) << endl;
    }
    return 0;
}