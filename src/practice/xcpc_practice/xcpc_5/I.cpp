#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        using pii = pair<int, int>;
        int n, m; cin >> n >> m;
        vector<pii> a(n * m + 1);

        for (int i = 0, x; i < n; i ++ ) for (int j = 0; j < m; j ++ ) 
        cin >> x, a[x] = {i, j};

        auto isValid = [&](int x) {
            vector<pii> tmp(n, {1e9, -1});
            for (int i = 0; i < x; i ++ ) {
                auto [x, y] = a[i];
                tmp[x] = {min(tmp[x].first, y), max(tmp[x].second, y)};
            }
            int num = -1;
            for (int j = 0; j < n; j ++ ) {
                if (tmp[j].second != -1) {
                    auto [mn, mx] = tmp[j];
                    if (num == -1) num = mx;
                    else {
                        if (num > mn) return false;
                        else num = mx;
                    }
                }
            }
            return true;
        };

        int l = 0, r = n * m;
        while (l < r) {
            int mid = l + r >> 1;
            if (isValid(mid)) l = mid + 1;
            else r = mid;
        }
        if (isValid(l + 1)) l ++ ;
        if (isValid(l - 1)) l -- ;

        cout << l << '\n';
        
    }
    return 0;
}