#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1); 
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int ans = 1;
        for (int i = 1; i < n; i ++ ) {int d = gcd(a[i], a[i + 1]); d = a[i] / d, ans = ans * d / gcd(ans, d);}
        
        cout << ans << endl;
    }
    return 0;
}