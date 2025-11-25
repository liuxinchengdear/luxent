#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        cout << "1 ";
        vector<int> a(n / 2);
        iota(a.begin(), a.end(), 1);
        for (int i = 0; i < n / 2; i ++ ) cout << a[i] << " ";
        for (int i = 0; i < (n - 1) / 2; i ++ ) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}