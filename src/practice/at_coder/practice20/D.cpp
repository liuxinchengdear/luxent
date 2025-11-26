#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int cnt = 0, mn = 1e9;
        for (int i = n; i ; i -- ) if (mn > a[i]) mn = a[i], cnt ++ ;

        cout << cnt << endl;
    }
    return 0;
}