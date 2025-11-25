#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i ++ ) cin >> s[i];

        vector<vector<bool>> st(n, vector<bool>(m));

        queue<int> q; q.push(0); st[0][0] = true;

        vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        vector<int> res; res.push_back(0);
        bool flag = false;
        int ttt = n * m - 1;
        while (q.size()) {
            auto num = q.front(); q.pop();
            int x = num / m, y = num % m;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                auto t = nx * m + ny;
                if (!st[nx][ny] && s[nx][ny] == '.') {
                    q.push(t), st[nx][ny] = true;
                    res.push_back(t);
                    flag = t == ttt;
                }
            }
        }

        if (flag) {cout << "0\n"; continue;}

        auto check = [&](int num, int dis) -> bool {
            int len = res.size();
            auto x = num / m, y = num % m;
            for (int i = 0; i < len; i ++ ) {
                auto nx = res[i] / m, ny = res[i] % m;
                if (abs(x - nx) + abs(y - ny) - 1 <= dis) return true;
            }
            return false;
        };

        auto binary_search = [&](int num) {
            int l = 0, r = n + m;
            while (l < r) {
                int mid = l + r >> 1;
                if (check(num, mid)) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        vector<int> tmp; tmp.push_back(ttt);

        q.push(n * m - 1); st[n - 1][m - 1] = true;
        while (q.size()) {
            auto num = q.front(); q.pop();
            int x = num / m, y = num % m;
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                auto t = nx * m + ny;
                if (!st[nx][ny] && s[nx][ny] == '.') {
                    q.push(t), st[nx][ny] = true;
                    tmp.push_back(t);
                }
            }
        }
        
        sort(res.begin(), res.end());
        sort(tmp.begin(), tmp.end());

        if (res.size() < tmp.size()) swap(res, tmp);

        int ans = 1e9;
        for (auto e : tmp) ans = min(ans, binary_search(e));
        cout << ans << '\n';
    }
    return 0;
}