#include <bits/stdc++.h>
using namespace std;;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        string s, f; cin >> s >> f;
        if (s.size() < 4) continue;
        s = s.substr(s.size() - 4); 
        if (s == ".log" && f[2] == 'x') res ++ ;
    }
    cout << res << endl;
    return 0;
}