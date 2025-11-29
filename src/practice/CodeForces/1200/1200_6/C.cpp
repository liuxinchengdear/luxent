#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(26);
        int mx = -1;
        for (auto c : s) a[c - 0x61] ++ , mx = max(mx, a[c - 0x61]);
        
        while (mx -- ) {
            for (int i = 0; i < 26; i ++ ) if (a[i]) a[i] -- , cout << char(i + 0x61);
        }
        cout << '\n';
    }
    return 0;
}