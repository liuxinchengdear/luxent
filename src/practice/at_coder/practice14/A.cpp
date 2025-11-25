#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t; cin >> n >> t;

    unordered_map<int, int> mp; mp[0] = n;
    vector<int> a(n + 1); int res = 1;
    for (int i = 0; i < t; i ++ ) {
        int x, y; cin >> x >> y;
        res -= !( -- mp[a[x]]); 
        a[x] += y;
        res += !mp[a[x]];
        mp[a[x]] ++ ;
        cout << res << endl;
    }
    return 0;
}