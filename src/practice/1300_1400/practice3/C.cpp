#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) cin >> b[i];

        if (a[n] != b[n]) {cout << "NO\n"; continue;}
        
        bool fg = false;
        for (int i = n - 1; i ; i -- ) {
            if (a[i] == b[i] || (a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i]) continue;
            fg = true; break;
        }

        cout << (fg ? "NO\n" : "YEs\n");
    }
    return 0;
}