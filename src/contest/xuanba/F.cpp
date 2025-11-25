#include <bits/stdc++.h>
using namespace std;


#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<pii> l(n), r(n);

    for (int i = 0; i < n; i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        l[i] = {a, c}; r[i] = {b, c};
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int cnt = 0, num = 0;
    int i = 0, j = 0;
    int pre = 0;
    while (i < n && j < n) {
        if (l[i].first < r[j].first) num += l[i ++ ].second;
        else num -= r[j ++ ].second;
        cnt = max(cnt, num);
    }
    cout << cnt << endl;

    return 0;
}