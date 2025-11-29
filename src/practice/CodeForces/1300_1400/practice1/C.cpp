#include <bits/stdc++.h>
using namespace std;

#define int long long

// optimal strategy
// O(n) Time Complexity

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(2 * n + 1);

        for (int i = 1; i <= n << 1; i ++ ) cin >> a[i];

        vector<int> gen(n + 1);
        for (int i = 1; i <= n; i ++ ) gen[i] = gen[i - 1] - a[i] + a[2 * n - i + 1];
        
        vector<int> spe(n + 1);
        for (int k = n - 1; k ; k -- ) spe[k] = -spe[k + 1] + a[k + 1] - a[2 * n - k];
    
        for (int i = 1; i <= n; i ++ ) cout << gen[i] + spe[i] << " \n"[i == n];
    }
    return 0;
}