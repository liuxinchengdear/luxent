#include <bits/stdc++.h>
using namespace std;

using tiii = tuple<int, int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    int q; cin >> q;

    int is = 0;

    vector<int> p(n), pre(q + 1);
    int pos = 0;
    for (int i = 1; i <= q; i ++ ) {
        int t, x; char c; cin >> t >> x >> c;
        pre[i] = (t == 1) * pre[i - 1] + (t == 2) - (t == 3);
        is = (t == 2) - (t == 3);
        if (t == 1) s[x - 1] = c, p[x - 1] = i;
        else pos = i;
    }
    
    for (int i = 0; i < n; i ++ ) {
        int t = pre[q];
        if (p[i] > pos) { cout << s[i]; continue; }
        cout << char(t ? t == 1 ? tolower(s[i]) : toupper(s[i]) : s[i]);
    }
    return 0;
}