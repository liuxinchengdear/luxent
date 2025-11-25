#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int res = 0;
        for (int mx = 1; mx <= n * n; mx ++ ) {
            map<int, int> fac;
            for (int i = mx; i; i -- ) {
                for (int j = 1; j <= mx / j; j ++ ) {
                    if (mx % j == 0) {
                        if (fac[j] >= 2 || fac[mx / j] >= 2) continue;
                        fac[j] ++ ; fac[mx / j] ++ ;
                    }
                }
            }
            for (int i = 1; i <= n; i ++ ) {
                
            }
        }
    }
    return 0;
}