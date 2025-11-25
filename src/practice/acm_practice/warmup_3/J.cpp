#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;
        vector<vector<int>> g(n + 1);

        vector<int> cntl(n + 1), cntr(n + 1);

        auto check = [&](int a, int b) -> void {
            if (s[a] == 'S' && s[b] == 'C') cntl[b] ++ ;
            if (s[a] == 'C' && s[b] == 'S') cntl[a] ++ ;
            if (s[a] == 'P' && s[b] == 'C') cntr[a] ++ ;
            if (s[a] == 'C' && s[b] == 'P') cntr[b] ++ ;
        };

        for (int i = 0; i + 1 < n; i ++ ) {
            int a, b; cin >> a >> b;
            g[a].push_back(b); g[b].push_back(a);
            check(a, b);
        }

        long long res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i] == 'C') {
                int ans1 = 0, ans2 = 0;
                for (auto b : g[i]) {
                    ans1 += cntl[b];
                    ans2 += (s[b] == 'P') * (cntr[b] - 1);
                }
                res += 1ll * ans1 * ans2;
            }
        }
        cout << res << '\n';
    }
    return 0;
}