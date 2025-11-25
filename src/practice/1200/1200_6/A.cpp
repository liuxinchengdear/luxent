#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        map<int, int> mp;
        for (int i = 0; i < n - 1; i ++ ) {
            mp[n - 1 + i * (n - i - 1)] ++ ;
            mp[(i + 1) * (n - i - 1)] += a[i + 1] - a[i] - 1;
        }
        mp[n - 1] ++ ;

        for (int x; q -- ; ) {
            cin >> x;
            cout << mp[x] << " ";
        }cout << '\n';
    }
    return 0;
}