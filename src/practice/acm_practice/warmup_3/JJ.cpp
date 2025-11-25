#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;
        vector<vector<int>> graph(n + 1);

        auto check1 = [&](int u, int v) -> bool {
            set<string> st = {"SC", "CC", "CP", "PC"};
            string t; t = s[u]; t += s[v];
            return st.count(t);
        };

        vector<int> cntl(n + 1), cntr(n + 1);
        auto check2 = [&](int u, int v) -> void {
            if (s[u] == 'S' && s[v] == 'C') cntl[v] ++ ;
            if (s[u] == 'C' && s[v] == 'S') cntl[u] ++ ;
            if (s[u] == 'P' && s[v] == 'C') cntr[u] ++ ;
            if (s[u] == 'C' && s[v] == 'P') cntr[v] ++ ;
        };

        for (int i = 0; i + 1 < n; i ++ ) {
            int a, b; cin >> a >> b;
            // if (check1(a, b)) graph[a].push_back(b);
            // if (check1(b, a)) graph[b].push_back(a);
            graph[a].push_back(b); graph[b].push_back(a);
            check2(a, b);
        }

        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i] == 'C') {
                int ans1 = 0, ans2 = 0;
                for (auto b : graph[i]) {
                    ans1 += (s[b] == 'C') * cntl[b];
                    ans2 += (s[b] == 'P') * (cntr[b] - 1);
                }
                res += ans1 * ans2;
            }
        }
        cout << res << '\n';
    }
    return 0;
}