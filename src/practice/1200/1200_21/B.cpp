#include <bits/stdc++.h>
using namespace std;

#define  int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int ft;
        map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x; 
            if (!i) {ft = x; continue;}
            mp[x] ++ ;
        }

        cout << (mp.begin() -> first <= ft - 1 ? "alice\n" : "bob\n");
    }
    return 0;
}