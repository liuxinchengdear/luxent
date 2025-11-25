#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int res = 1e9;
        for (int i = 0; i <= 2; i ++ ) {
            for (int j = 0; j <= 1; j ++ ) {
                for (int k = 0; k <= 4; k ++ ) {
                    for (int l = 0; l <= 2; l ++ ) {
                        int num = i * 1 + j * 3 + k * 6 + l * 10;
                        if (num > n || (n - num) % 15) continue;
                        res = min(i + j + k + l + (n - num) / 15, res);
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}