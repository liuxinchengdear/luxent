#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        vector<int> a(n + 1);

        int sum = 0, cnt = 0;
        for (int i = n; i ; i -- ) {
            if (s[i] == 0x31 && cnt ++ < n >> 1) sum += i, a[i] = 1;
        }

        set<int> st;
        for (int i = 1, tmp = 0; i <= n; i ++ ) {
            if (a[i]) st.insert(i);
            tmp += a[i];
            if (tmp > i >> 1) tmp -- , sum -= *st.begin(), st.erase(st.begin());
        }

        cout << n * (n + 1) / 2 - sum << endl;
    }
    return 0;
}