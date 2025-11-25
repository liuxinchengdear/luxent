#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                int x; cin >> x;
                if (j == i) s1 += x;
                if (j + i == n + 1) s2 += x;
            }
        }
        cout << abs(s1 - s2) << endl;
    }
    return 0;
}