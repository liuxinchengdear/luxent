#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        string s; cin >> s;

        vector<bool> st(n);

        for (int i = 0; i < n; i ++ ) {
            if (s[i] == 0x31) {
                for (int j = i; j <= i + k && j < n; j ++ ) st[j] = true;
            }
        }

        cout << count(st.begin(), st.end(), false) << endl;
    }
    return 0;
}