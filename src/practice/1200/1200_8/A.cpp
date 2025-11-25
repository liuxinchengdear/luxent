#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string a, b; cin >> a >> b;
        int n = a.size(), m = b.size();

        int ans = n + m;
        for (int i = 0; i < m; i ++ ) {
            int j = i;
            for (auto c : a) if (j < m && b[j] == c) j ++ ;
            ans = min(ans, n + m - (j - i));
        }
        cout << ans << '\n';
    }
    return 0;
}