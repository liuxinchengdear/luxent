#include <bits/stdc++.h>
using namespace std;

struct People {
    int a, b; int idx;

    bool operator < (const People &x) const {
        return a < x.a || a == x.a && b > x.b;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<People> ren(n + 1);
        vector<int> rate(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            int a, b; cin >> a >> b;
            ren[i] = {a, b, i}; rate[a] ++ ;
        }
        sort(ren.begin() + 1, ren.end());

        auto check = [&](int x) -> bool {
            int cnt = 0;
            for (int i = 1; i <= n;) {
                int diff = rate[ren[i].a];
                for (int j = min(diff, x - cnt); j; j -- ) {
                    if (x - (j + cnt) <= ren[i + j - 1].b) 
                    {cnt += j; break;}
                }
                i += diff;
            }
            return cnt >= x;
        };

        auto binary_search = [&]() -> int {
            int l = 1, r = n; 
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid)) l = mid + 1;
                else r = mid;
            }
            if (!check(l)) l -- ;
            return l;
        };

        auto creat = [&](int x) -> vector<int> {
            int cnt = 0;
            vector<int> res;
            for (int i = 1; i <= n;) {
                int diff = rate[ren[i].a];
                for (int j = min(diff, x - cnt); j; j -- ) {
                    if (x - (j + cnt) <= ren[i + j - 1].b) {
                        for (int k = i; k < i + j; k ++ ) {
                            auto [a, b, c] = ren[k];
                            res.push_back(c);
                        }
                        cnt += j; break;
                    }
                }
                i += diff;
            }
            return res;
        };

        auto t = binary_search();
        vector<int> res = creat(t);
        cout << t << '\n';
        for (int i = 0; i < t; i ++ ) cout << res[i] << " \n"[i == t - 1];
    }
    return 0;
}