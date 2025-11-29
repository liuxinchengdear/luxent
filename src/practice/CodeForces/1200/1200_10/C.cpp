#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int ans = 1e9;
        for (int i = 1; i <= n; i ++ ) {
            int len = 0;
            if (a[i] == a[1]) while (i <= n && a[i] == a[1]) i ++ , len ++ ;
            ans = min(len, ans); 
        }

        cout << (ans < n ? ans : -1) << '\n';
    }
    return 0;
}