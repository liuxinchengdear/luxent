#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i ++ ) cin >> s[i];

    queue<int> q;
    vector<vector<bool>> st(n, vector<bool>(m));

    int sum = 0;

    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (s[i][j] == '#') q.push(i * m + j), st[i][j] = true, sum ++ ;
        }
    }

    vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    auto outline = [&](int x, int y) -> bool 
    {return x < 0 || x >= n || y < 0 || y >= m;};

    auto check = [&](int x, int y) -> bool {
        if (outline(x, y) || st[x][y]) return false;
        int cnt = 0;
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!outline(nx, ny) && st[nx][ny]) cnt ++ ;
        }
        return cnt == 1;
    };

    while (q.size()) {
        auto size = q.size(); 
        vector<int> add;
        while (size -- ) {
            auto t = q.front(); q.pop();
            int x = t / m, y = t % m;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (check(nx, ny)) add.push_back(nx * m + ny);
            }
        }
        sum += add.size();
        for (auto e : add) {
            int x = e / m, y = e % m;
            st[x][y] = true; q.push(e);
        }
    }

    cout << sum << '\n';
    return 0;
}