#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++ i) {
            cin >> a[i];
        }

        vector<bool> st(n + 1);
        for (int i = n - 1; i >= 1; -- i) {
            for (int j = n; j > i; -- j) {
                if (!st[j] && a[i] > a[j]) st[j] = true;
            }
        }

        cout << count(st.begin(), st.end(), true) << endl;
    }
    return 0;
}