#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    list<pii> a;
    for (int i = 1; i <= n; i ++ ) 
    {int x; cin >> x;a.push_back({i, x});}
    string s; cin >> s;

    auto p = a.begin();
    auto dir = 1;
    for (int i = 0; i < m; i ++ ) {
        auto ch = s[i];
        p -> second -- ;
        auto num = p -> second;

        auto move = [&](auto &p) -> void {
            if (p == a.begin() && dir == -1) {p = prev(a.end()); return;}
            if (p == prev(a.end()) && dir == 1) {p = a.begin(); return;}
            advance(p, dir);
        };

        if (!num) {
            auto tp = p;
            if (ch == 'C') move(p), a.erase(tp);
            else if (ch == 'S') move(p), a.erase(tp), move(p);
            else if (ch == 'D') move(p), p -> second += 2, a.erase(tp), move(p);
            else if (ch == 'R') dir *= -1, move(p), a.erase(tp);
            continue;
        }
        
        if (ch == 'C') move(p);
        else if (ch == 'S') move(p), move(p);
        else if (ch == 'D') move(p), p -> second += 2, move(p);
        else if (ch == 'R') dir *= -1, move(p);
    }

    vector<int> num(n + 1);
    for (auto [id, x] : a) num[id] = x;

    for (int i = 1; i <= n; i ++ ) cout << num[i] << '\n';

    return 0;
}