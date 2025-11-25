#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s, t; cin >> s >> t;
    s = " " + s; t = " " + t;

    int sA = count(s.begin(), s.end(), 'A') ,tA = count(t.begin(), t.end(), 'A');
    
    if (sA == n || sA == 0 || tA == n || tA == 0) {
        cout << (sA == tA ? 0 : -1) << endl;
        return 0;
    }

    int stA = 0, edB = 0;
    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (t[i] == 'A' && !stA) stA = i;
        if (t[i] == 'B') edB = i;
        if (t[i] != s[i]) sa += s[i] == 'A', sb += s[i] == 'B';
    }
    stA = min(stA, n - 1); edB = max(edB, 2LL);
    
    bool flag = false;
    for (int i = 1; i < stA; i ++ ) if (s[i] == 'A') flag = true;
    // if (s[stA] == 'B') flag = true;
    for (int i = edB + 1; i <= n; i ++ ) if (s[i] == 'B') flag = false;
    if (s[edB] == 'A' && stA > edB) flag = true;
    
    cout << (flag ? -1 : (int)max(sa, sb)) << endl;
    return 0;
}