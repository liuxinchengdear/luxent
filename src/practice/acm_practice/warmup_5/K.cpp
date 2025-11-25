#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i ++ ) cin >> s[i];

        vector<array<int, 2>> dir{{0, 1}, {1, 0}};
        queue<int> q;
        vector<vector<bool>> st(n, vector<bool>(n));

        auto check = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < n && !st[x][y] && s[x][y] == '.';
        };

        
        q.push(0); st[0][0] = true;
        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t / n, y = t % n;
            bool flag = true;
            for (int i = 0; i < 2; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (flag && check(nx, ny)) {
                    q.push(nx * n + ny); st[nx][ny] = true;
                    flag = false;
                }
            }
        }

        dir[0] = {1, 0}; dir[1] = {0, 1};

        q.push(0);
        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t / n, y = t % n;
            bool flag = true;
            for (int i = 0; i < 2; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (flag && check(nx, ny)) {
                    q.push(nx * n + ny); st[nx][ny] = true;
                    flag = false;
                }
            }
        }

        int res = st[n - 2][n - 1] + st[n - 1][n - 2];
        cout << res << '\n';
    }
    return 0;
}