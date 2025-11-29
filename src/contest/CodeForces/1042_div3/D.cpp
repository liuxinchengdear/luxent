#include <bits/stdc++.h>
using namespace std;

// 注意观察题目

#define MULTI int _T; cin >> _T; while (_T -- )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        int n; cin >> n;
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < n - 1; i ++ ) {
            int a, b; cin >> a >> b;
            g[a].push_back(b); g[b].push_back(a);
        }

        if (n == 2) { cout << "0\n"; continue; }

        int res = 0;
        for (int i = 1; i <= n; i ++ ) res += int(g[i].size() == 1);

        int mx = 0;
        for (int i = 1; i <= n; i ++ ) {
            int cnt = 0;
            for (auto j : g[i]) cnt += int(g[j].size() == 1);
            mx = max(mx, cnt);
        }

        cout << res - mx << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}