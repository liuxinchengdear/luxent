#include <bits/stdc++.h>
using namespace std;

struct Monster {
    int hp, dmg;
    bool operator < (const Monster &x) const {return hp < x.hp;}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        vector<Monster> mst(n + 1);
        for (int i = 1; i <= n; i ++ ) {int x; cin >> x; mst[i].hp = x;}
        for (int i = 1; i <= n; i ++ ) {int x; cin >> x; mst[i].dmg = x;}

        sort(mst.begin() + 1, mst.end());

        vector<int> suff(n + 2), pre(n + 1); 
        suff[n + 1] = 1e9;

        for (int i = 1; i <= n; i ++ ) {
            auto [a, b] = mst[i];
            pre[i] = a;
        }
        for (int i = n; i ; i -- ) {
            auto [a, b] = mst[i];
            suff[i] = min(b, suff[i + 1]);
        }

        int sum = 0;
        for (int i = 1; i <= n && k > 0; ) {
            sum += k;
            i = lower_bound(pre.begin(), pre.end(), sum + 1) - pre.begin();
            if (i <= n) k -= suff[i];
        }

        cout << (k > 0 ? "YES\n" : "NO\n");
    }
    return 0;
}