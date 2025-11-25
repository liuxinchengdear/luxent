#include <bits/stdc++.h>
using namespace std;

struct Stuff {
    int las;
    vector<int> id, cost;
};

struct Machine {
    array<int, 8010> time;
};

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n; cin >> m >> n;
    vector<pii> seq(n * m); vector<int> cnt(n + 1);
    for (auto &[e, t] : seq) cin >> e, t = ++ cnt[e];

    vector<Stuff> a(n + 1);

    for (int i = 1; i <= n; i ++ ) {
        auto &t = a[i].id; t.resize(m + 1);
        for (int j = 1; j <= m; j ++ ) cin >> t[j];
    }

    for (int i = 1; i <= n; i ++ ) {
        auto &t = a[i].cost; t.resize(m + 1);
        for (int j = 1; j <= m; j ++ ) cin >> t[j];
    }

    vector<Machine> mac(m + 1);

    int res = 0;
    for (auto [id, num] : seq) {
        auto eng = a[id].id[num], cost = a[id].cost[num]; auto &las = a[id].las;
        auto &t = mac[eng].time;
        for (int i = las + 1, s = 0; ; i ++ ) {
            if (!t[i]) s ++ ;
            else s = 0;
            if (s == cost) {
                fill(t.begin() + i - cost + 1, t.begin() + i + 1, id);
                res = max(res, i);
                las = i; break;
            }
        }
    }
    
    cout << res << endl;

    return 0;
}