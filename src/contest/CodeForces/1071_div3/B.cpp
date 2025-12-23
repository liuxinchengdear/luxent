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

        int res = 0; 
        for (int i = 2; i <= n; ++ i) res += abs(a[i] - a[i - 1]);
        
        int tmp = 0;
        for (int i = 1; i <= n; ++ i) {
            int t;
            if (i == 1) t = -abs(a[2] - a[1]);
            else if (i == n) t = -abs(a[n] - a[n - 1]);
            else t = abs(a[i + 1] - a[i - 1]) - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]);
            tmp = min(tmp, t);
        }

        cout << res + tmp << endl;
    }
    return 0;
}