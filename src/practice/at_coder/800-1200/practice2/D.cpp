#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;

using namespace __gnu_cxx;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    rope<char> ser;
    vector<rope<char>> pc(n + 1);

    while (q -- ) {
        int op, p; string s; cin >> op >> p;
        if (op == 1) {
            pc[p] = ser;
        }
        else if (op == 2) {
            cin >> s; pc[p].append(s.c_str());
        }
        else ser = pc[p];
    }
    cout << ser << endl;
    return 0;
}