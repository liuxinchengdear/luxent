#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i ++ ) {
            int num = s[i], p = i;
            for (int j = i + 1; j <= min(i + 9, n - 1); j ++ ) {
                if (s[j] - (j - i) > num) p = j, num = s[j] - (j - i);
            }
            while (p > i) swap(s[p], s[p - 1]), p -- ;
            s[i] = num;
        }
        cout << s << endl;
    }
    return 0;
}