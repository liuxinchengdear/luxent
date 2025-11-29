#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;

        vector<string> g(n +  1);
        for (int i = 1; i <= n; i ++ ) cin >> g[i], g[i] = " " + g[i];

        auto outline = [&](int x, int y) -> bool {
            return x < 1 || x > n || y < 1 || y > m;
        };

        vector<array<int, 2>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> st(n + 2, vector<bool>(m + 2));

        auto dfs = [&](this auto &&dfs, int x, int y, int num, int op, string &tmp) -> int {
            if (!num) {
                int n = tmp.size(), cnt = 0;
                for (int i = 0; i < n; i ++ ) {
                    cnt += tmp[i] == 0x31 && tmp[(i + 1) % n] == 0x35 && tmp[(i + 2) % n] == 0x34 && tmp[(i + 3) % n] == 0x33;
                }
                return cnt;
            }
            st[x][y] = true; tmp += g[x][y];
            int nx = x + dir[op % 4][0], ny = y + dir[op % 4][1];

            int cnt = 0;
            if (st[nx][ny] && op % 4 == 3) {
                int n = tmp.size();
                for (int i = 0; i < n; i ++ ) {
                    cnt += tmp[i] == 0x31 && tmp[(i + 1) % n] == 0x35 && tmp[(i + 2) % n] == 0x34 && tmp[(i + 3) % n] == 0x33;
                } 
                tmp = ""; 
            }

            if (outline(nx, ny) || st[nx][ny]) nx = x + dir[( ++ op) % 4][0], ny = y + dir[op % 4][1];
            
            
            return dfs(nx, ny, num - 1, op, tmp) + cnt;
        };

        string tmp = "";
        cout << dfs(1, 1, n * m, 0, tmp) << endl;
    }
    return 0;
}