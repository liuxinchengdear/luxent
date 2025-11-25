#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        if (n == 1) {cout << "1\n"; continue;}
        if (n & 1) {cout << "-1\n"; continue;}

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            i & 1 ? a[i + 1] = i : a[n + 1 - i] = i;
        }

        for (int i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
    }
    return 0;
}
