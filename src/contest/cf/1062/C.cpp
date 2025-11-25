#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n);
        int odd = 0, even = 0;
        for (auto &e : a) {
            cin >> e; 
            odd += e & 1; even += e % 2 == 0;
        }
        if (odd == n || even == n) {}
        else sort(a.begin(), a.end());

        for (auto e : a) cout << e << " "; cout << endl;
    }
    return 0;
}