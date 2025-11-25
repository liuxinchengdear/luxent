#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, X; cin >> n >> X;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        sort(a.begin() + 1, a.end(), greater<int>());

        vector<int> res; int ans = 0;
        for (int i = 1, j = n, sum = 0; i <= j; ) {
            if ((a[i] + sum) / X > sum / X) { res.push_back(a[i]); ans += a[i]; sum += a[i ++ ]; continue; }
            while (j >= i && (a[j] + sum) / X == sum / X) res.push_back(a[j]), sum += a[j -- ];
        }
        cout << ans << '\n';
        for (auto e : res) cout << e << " ";
        cout << endl;
    }
    return 0;
}