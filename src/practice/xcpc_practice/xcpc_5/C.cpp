#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        using pii = pair<int, int>;
        int n; cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; i ++ ) {
            int w, num; cin >> w >> num;
            a[i] = {w, num};
        }

        sort(a.begin(), a.end());

        int res = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int num = min(a[i].second, a[j].second);
            res += (a[j].first - a[i].first) * num;
            a[i].second -= num; a[j].second -= num;
            if (!a[i].second) i ++ ;
            if (!a[j].second) j -- ;
        }
        cout << res << '\n';
    }
    return 0;
}