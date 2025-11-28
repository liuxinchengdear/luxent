#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; string s; cin >> n >> s;
    int q; cin >> q;

    vector<int> c(27); iota(c.begin(), c.end(), 0);
    vector<pii> tmp;
    while (q -- ) {
        char a, b; cin >> a >> b; a -= 0x60; b -= 0x60;
        tmp.emplace_back(a, b);
    }

    while (tmp.size()) {
        auto [a, b] = tmp.back(); tmp.pop_back();;
        c[a] = c[b];
    }
    for (auto ch : s) cout << char(c[ch - 0x60] + 0x60); cout << endl;
    return 0;
}