#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        auto binary_search = [&](int pos) -> int {
            int l = 0, r = a.size();
            while (l < r) {
                int mid = l + r >> 1;
                if (a[mid] - a[pos] >= n) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        int res = 1;
        for (int i = 0; i < a.size(); i ++ ) {
            res = max(res, binary_search(i) - i);
        }
        cout << res << '\n';
    }
    return 0;
}