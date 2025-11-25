#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x;
            if (x & 1) odd += x;
            else even += x;
        }
        cout << (even > odd ? "Yes\n" : "No\n");
    }
    return 0;
}