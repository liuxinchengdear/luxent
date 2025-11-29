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

        sort(a.begin(), a.end(), greater<int>());

        auto binary_search = [&](int l, int r, int x) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (a[mid] >= x) l = mid + 1;
                else r = mid;
            }
            if (l == n || a[l] < x) l -- ;
            return l;
        };

        int cnt = 0;
        for (int i = 0; i < n - 2; i ++ ) {
            for (int j = i + 1; j < n - 1; j ++ ) {
                int sum = a[i] + a[j];
                if (i) {
                    auto k = binary_search(j + 1, n, a.front() + 1 - sum);
                    auto nk = binary_search(j + 1, n, a[i] - a[j] + 1);
                    cnt += min(k, nk) - j;
                }
                else {
                    auto k = binary_search(j + 1, n, a[i] - a[j] + 1);
                    cnt +=k - j;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}