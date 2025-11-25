#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int num = 0;
        for (int i = 1, x; i <= n; i ++ ) cin >> x, num = max(num, i * x);

        vector<vector<int>> g(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) cin >> g[i][j];
        }

        vector<bool> st(n + 1);
        queue<int> q; q.push(g[num][1]); st[q.front()] = true;

        while (q.size()) {
            auto t = q.front(); q.pop();
            if (t == num) break;
            for (int i = 1; i <= n; i ++ ) {
                auto &tt = g[t][i];
                if (!st[tt]) {q.push(tt); st[tt] = true; break;}
            }
        }
        cout << (count(st.begin() + 1, st.end(), false) > 1 ? "lieren\n" : "langren\n");
    }
    return 0;
}