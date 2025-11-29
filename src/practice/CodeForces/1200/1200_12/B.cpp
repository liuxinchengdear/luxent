#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n);
        // 找到最小公因数
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        sort(a.begin(), a.end());
        int num = a[0];
        for (int i = 1; i < n; i ++ ) num = gcd(num, a[i]);

        int cnt = count(a.begin(), a.end(), num);
        cout << (cnt > 1 ? "NO\n" : "YES\n");
    }
    return 0;
}