#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m; cin >> n >> m;
        if (n * (n + 1) >> 1 < m || m < n) {cout << "-1\n"; continue;}

        vector<vector<int>> g(n + 1);

        vector<int> tmp(n); iota(tmp.begin(), tmp.end(), 1);
        set<int> st(tmp.begin(), tmp.end());
        
        m -= n; int las = 1, u = 1;
        for (int i = 1; i <= n && m > 0; i ++ ) {
            int x = min(n - i, m); m -= x;
            if (i == 1) {las = 1 + x; u = 1 + x; st.erase(las); continue;}
            g[las].push_back(x + 1); las = x + 1; st.erase(x + 1);
        }  

        if (st.count(las)) st.erase(las);
        for (auto v : st) {
            g[las].push_back(v); las = v;
        }
        cout << u << endl;
        for (int i = 1; i <= n; i ++ ) {
            for (auto e : g[i]) cout << i << " " << e << '\n';
        }
    }
    return 0;
}