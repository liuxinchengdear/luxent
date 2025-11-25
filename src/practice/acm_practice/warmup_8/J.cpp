#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; string s; cin >> k >> s;
    int n = s.size();
    unordered_set<string> str{"lose", "los", "loe", "lse", "ose", "lo", "ls", "le", "os", "oe", "se", "l", "o", "s", "e"};

    int res = 0;
    for (int len = 4; len; len -- ) {
        for (int i = 0; i <= n - len; i ++ ) {
            string ts = s.substr(i, len);
            if (str.count(ts)) res ++ ;
        }
    }
}