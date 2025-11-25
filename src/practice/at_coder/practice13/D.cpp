#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int n = s.size(), res = 0;
    
    vector<int> a(150); bool fg = false;
    for (int i = n - 1; i >= 0; i -- ) {
        res += n - i - ( ++ a[s[i]]);
        if (a[s[i]] > 1) fg = true;
    }

    cout << res + fg << endl;

    return 0;
}