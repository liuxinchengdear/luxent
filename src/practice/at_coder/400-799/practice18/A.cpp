#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int n = s.size(); string res;
    for (int i = n - 1; i >= 0; i -- ) {
        res.push_back(s[i]);
        if (res.size() >= 3) {
            string tmp = res.substr(res.size() - 3);
            if (tmp == "CBA") res.pop_back(), res.pop_back(), res.pop_back();
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}