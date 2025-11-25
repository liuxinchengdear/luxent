#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < n - 2; i ++ ) cnt += s[i] == s[i + 2];
        cout << n - 1 - cnt << '\n';
    }
    return 0;
}