#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    using pii = pair<int, int>;

    int _T; cin >> _T; while (_T -- ) {
        int n, m, h; cin >> n >> m >> h;
        vector<pii> res(n);
        for (int i = 0; i < n; i ++ ) {
            vector<int> vi(m);
            for (int j = 0; j < m; j ++ ) {
                cin >>vi[j];
            }
            sort(vi.begin(),vi.end());
            int num = 0, j, sum = 0;
            for (j = 0; j < m; j ++ ) {
                if (num + vi[j] > h) break;
                num += vi[j];
                sum += num;
            }
            res[i] = {j, sum};
        }
        pii t = res[0];
        sort(res.begin(), res.end(), [](pii x, pii y) {
            return x.first > y.first || x.first == y.first && x.second < y.second;
        });
        auto p = find(res.begin(), res.end(), t) - res.begin();
        cout << p + 1 << '\n';
    }
    return 0;
}