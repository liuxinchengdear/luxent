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

        if (n == 2) { cout << "Yes\n"; continue; }

        sort(a.begin() + 1, a.end(), [](int x, int y) -> bool {
            return abs(x) < abs(y);
        });

        if (abs(a[1]) == abs(a[n])) { 
            int n1 = count(a.begin(), a.end(), abs(a.back())), n2 = count(a.begin(), a.end(), -abs(a.back()));
            cout << (n1 == n || !n1 ? "Yes\n" : abs(n1 - n2) <= 1 ? "Yes\n" : "No\n");
            continue; 
        }

        bool fg = true;
        for (int i = 1; i + 2 <= n; i ++ ) {
            if (a[i + 1] * a[i + 1] != a[i] * a[i + 2]) { fg = false; break; }
        }
        cout << (fg ? "Yes\n" : "No\n");
    }
    return 0;
}