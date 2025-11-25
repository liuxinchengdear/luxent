#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        
        int sum = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];
        for (int i = 0; i < n; i ++ ) cin >> b[i], sum += b[i];

        sort (a.begin(), a.end(), greater<int>());
        sort (b.begin(), b.end());

        int cnt = 0;
        for (int i = 0, j = 0; i < n; i ++ , j ++ ) {
            while (j < n && a[i] + b[j] < m) j ++ ;
            cnt += j < n;
        }
        cout << sum - 1ll * cnt * m << '\n';
    }
    return 0;
}