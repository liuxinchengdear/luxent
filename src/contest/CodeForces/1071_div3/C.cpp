#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        sort(a.begin(), a.end());

        cout << max(a[2] - a[1], a[1]) << endl;
    }
    return 0;
}