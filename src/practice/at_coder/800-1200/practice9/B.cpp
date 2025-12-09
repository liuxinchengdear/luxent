#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m; 
    string s, t; cin >> s >> t;

    int nt = t.back();
    sort(t.begin(), t.end());

    for (int i = 0; i < n; ++ i) if (t.size() && t.back() > s[i]) s[i] = t.back(), t.pop_back();

    if (!count(s.begin(), s.end(), nt)) {
        if (count(t.begin(), t.end(), s.back())) for (int i = 0; i < n; ++ i) if (s.back() > s[i]) { s[i] = s.back(); break; }
        s.back() = nt;
    }

    cout << s << endl;
    
    return 0;
}