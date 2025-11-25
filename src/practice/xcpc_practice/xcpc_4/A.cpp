#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, s, v; cin >> n >> s >> v;

        cout << (n <= s * v ? 1 : 0) << '\n';
    }
    return 0;
}