#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());

    do {
        bool fg = true;
        for (int i = 0; i + 1 < n; i ++ ) {
            auto s1 = a[i], s2 = a[i + 1];
            int cnt = 0;
            for (int j = 0; j < m; j ++ ) {
                if (s1[j] != s2[j]) cnt ++ ;
            }
            if (cnt > 1) { fg = false; break; }
        }
        if (fg) { cout << "Yes\n"; exit(0); }
    } while (next_permutation(a.begin(), a.end()));

    cout << "No\n"; 
    return 0;
}