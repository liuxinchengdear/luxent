#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h, k; cin >> n >> m >> h >> k;
    string s; cin >> s;

    set<pii> st;
    for (int i = 0; i < m; i ++ ) {
        int x, y; cin >> x >> y; 
        st.insert({x, y});
    }

    map<int, pii> mp{{'U', {0, 1}}, {'D', {0, -1}}, {'R', {1, 0}}, {'L', {-1, 0}}};
    
    queue<pii> q; q.push({0, 0});
    bool fg = true; int i = 0;
    // if (st.count({0, 0}) && h < k) h = k, st.erase({0, 0});
    while (q.size() && i < n) {
        if (h <= 0) { fg = false; break; }
        auto [x, y] = q.front(); q.pop();
        auto [dx, dy] = mp[s[i ++ ]];
        auto nx = x + dx, ny = y + dy;
        if ( -- h < k && st.count({nx, ny})) h = k, st.erase({nx, ny});
        q.push({nx, ny});
    }

    cout << (fg ? "Yes\n" : "No\n");
    return 0;
}