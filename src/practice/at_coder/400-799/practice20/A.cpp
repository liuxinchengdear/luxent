#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Peo {
    int id; long double r;

    bool operator > (const Peo &x) const {
        return r > x.r || r == x.r && id < x.id;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Peo> t(n);
    for (int i = 0; i < n; i ++ ) {
        long double a, b; cin >> a >> b;
        t[i] = {i + 1, a / (a + b)};
    }

    sort(t.begin(), t.end(), greater<Peo>());

    for (int i = 0; i < n; i ++ ) {
        auto [id, r] = t[i];
        cout << id << " \n"[i == n - 1];
    }

    return 0;
}