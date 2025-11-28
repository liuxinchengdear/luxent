#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    map<int, int> mp;

    for (int i = 0; i < m; i ++ ) {
        int a, b; cin >> a >> b;
        mp[a - b] = mp[a - b] ? min(mp[a - b], a) : a;
    }

    int cnt = 0;
    for (auto [k, v] : mp) {
        if (k >= n) break;
        if (n < v) continue;
        cnt += (n - v) / k; n = v + (n - v) % k;
        while (n >= v) n -= k, cnt ++ ;
    }

    cout << cnt << endl;
    return 0;
}