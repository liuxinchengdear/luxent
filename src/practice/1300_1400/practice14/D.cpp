#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
    
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
        }

        sort(a.begin() + 1, a.end());
        int len = 0;
        for (int i = 1; i + 1 < n; i ++ ) {
            auto t = a[i] + a[i + 1];
            auto p = lower_bound(a.begin(), a.end(), t) - a.begin();

            len = max(len, p - i);
        }

        cout << n - len << endl;
    }
    return 0;
}