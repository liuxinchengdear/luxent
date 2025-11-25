#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        array<array<int, 3>, 2> peo;

        int mn = 1e9;

        for (int i = 0; i < 2; i ++ ) {
            for (int j = 0; j < 3; j ++ ) 
            {auto &t = peo[i][j]; cin >> t; mn = min(mn, t);}
        }


    }
}