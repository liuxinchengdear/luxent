#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &e : a) cin >> e, mp[e] ++ ;

    long long res = 0;
    for (int i = 0; i < n; i ++ ) {
        if (i && a[i] == a[i - 1]) {mp[a[i]] -- ; continue;}
        res += n - 1 - i - -- mp[a[i]];
    }
    cout << res + 1 << '\n';
    return 0;
}