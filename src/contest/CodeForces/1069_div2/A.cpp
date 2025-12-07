#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<int> b = a;
        
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        auto p = lower_bound(a.begin(), a.end(), a.size() - 1);

        int cnt = *p - a.size() + 1;
        cout << a.size() - 1 + cnt << endl;
    }
    return 0;
}