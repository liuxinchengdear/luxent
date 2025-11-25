#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; cin >> s >> t;
    int lns = s.size(), lnt = t.size();

    if (lns != lnt) {cout << "No" << endl; return 0;}
    for (int i = 0; i < lns; i ++ ) {
        string tmp = s.substr(i) + s.substr(0, i);
        if (tmp == t) {cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
    return 0;
}