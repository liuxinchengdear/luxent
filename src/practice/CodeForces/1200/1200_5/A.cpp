#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, x; cin >> n >> x;
        map<int, int> mp, tmp;
        for (int i = 0, x; i < n; i ++ ) cin >> x, mp[x] ++ ;
        
        for (int i = 0; i <= n; i ++ ) {
            tmp[i % x] += mp.count(i) ? mp[i] : 0;
            if (!mp.count(i) && tmp[i % x] <= i / x) 
            {cout << i << '\n'; break;}
        }
    }
    return 0;
}