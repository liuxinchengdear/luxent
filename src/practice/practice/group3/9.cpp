#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    map<pii, int> mp;
    for (int i = 0; i < m; i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        mp[{a, b}] = max(mp[{a, b}], c); swap(a, b);
        mp[{a, b}] = max(mp[{a, b}], c);
    }

    vector<int> a(n); iota(a.begin(), a.end(), 1);

    int res = 0;
    do {
        int tmp = 0;
        for (int i = 0; i + 1 < n; i ++ ) {
            auto t = mp[{a[i], a[i + 1]}];
            if (t) tmp += t;
            else res = max(res, tmp), tmp = 0;
        }
        res = max(res, tmp);
    } while (next_permutation(a.begin(), a.end()));

    cout << res << endl;
    return 0;
}