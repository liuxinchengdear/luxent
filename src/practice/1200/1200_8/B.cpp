#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1), tm(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i]; 
        
        for (int i = n; i; i -- ) {
            if (i == n) tm[i] = a[i];
            else tm[i] = tm[i + 1] + max(a[i] - tm[i + 1], 1LL);
        }
        cout << tm[1] << '\n';
    }
    return 0;
}