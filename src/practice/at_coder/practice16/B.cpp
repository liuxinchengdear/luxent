#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 
    int q; cin >> q;

    map<int, pii> mp{{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};

    vector<pii> res;
    for (int i = n; i ; i -- ) res.push_back({i, 0});

    int cnt = 0;
    while (q -- ) {
        int op; int p; char c;
        cin >> op;

        if (op == 1) {
            cin >> c; ++ cnt;
            auto [x, y] = res.back();
            auto [dx, dy] = mp[c];
            res.push_back({x + dx, y + dy});
        }
        else {
            cin >> p; p = n - p;
            auto [x, y] = res[p + cnt];
            cout << x << " " << y << endl;
        }
    }
    return 0;
}