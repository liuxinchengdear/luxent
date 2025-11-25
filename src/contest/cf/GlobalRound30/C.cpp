#include <bits/stdc++.h>
using namespace std;

struct Mon {
    int hp, c;

    bool operator < (const Mon &x) const {
        return hp < x.hp;
    }

    bool operator > (const Mon &x) const {
        return hp > x.hp;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        multiset<int> swd;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; swd.insert(x);
        }

        vector<Mon> mon(m);
        for (int i = 0; i < m; i ++ ) cin >> mon[i].hp;
        for (int i = 0; i < m; i ++ ) cin >> mon[i].c;

        vector<Mon> m1, m0;
        for (int i = 0; i < m; i ++ ) {
            if (mon[i].c) m1.push_back(mon[i]);
            else m0.push_back(mon[i]);
        }

        sort(m1.begin(), m1.end());


        int res = 0;
        for (int i = 0; i < m1.size(); i ++ ) { auto [hp, c] = m1[i];
            auto p = swd.lower_bound(hp);
            if (p == swd.end()) break;
            swd.insert(max(*p, c)); swd.erase(p); res ++ ;
        }

        vector<int> a(swd.begin(), swd.end());

        sort(a.begin(), a.end(), greater<int>());
        sort(m0.begin(), m0.end(), greater<Mon>());

        for (int i = 0, j = 0; i < a.size() && j < m0.size(); ) {
            if (a[i] >= m0[j].hp) { res ++ ; j ++ ; i ++ ; }
            else j ++ ;
        }

        cout << res << endl;
    }
    return 0;
}