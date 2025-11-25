#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> team(m + 1);
    for (int i = 1; i <= m; i ++ ) 
    {cin >> team[i], team[i] = " " + team[i];}

    array<int, 3> r, p;
    for (int i = 0; i < 3; i ++ ) cin >> r[i];
    for (int i = 0; i < 3; i ++ ) cin >> p[i];

    int mn = max(0, n - 13), mx = n - 10;

    for (int i = 0; i < 1 << n; i ++ ) {
        int cnt = popcount(static_cast<unsigned int>(i));
        if (cnt >= mn && cnt <= mx) {
            auto tmp = i;
            vector<bool> st(n + 1);
            for (int j = 0; tmp; j ++ ) {
                if (tmp & 1) st[j + 1] = true;
                tmp >>= 1;
            }
            vector<int> res(m + 1);
            for (int i = 1; i <= m; i ++ ) {
                for (int j = 1; j <= n; j ++ ) {
                    res[i] += team[i][j] == 0x31 && !st[n - j + 1];
                }
            }
            sort(res.begin() + 1, res.end(), greater<int>());

            if (res[r[0]] == p[0] && res[r[1]] == p[1] && res[r[2]] == p[2]) {
                cout << n - cnt << '\n';
                for (int i = 1; i <= n; i ++ ) {
                    if (!st[n - i + 1]) cout << i << " ";
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}