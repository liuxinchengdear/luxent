#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a = {0, 4, 8, 3, 7, 2, 6, 1, 5};
    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s;
        int sum = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            sum += s[i] - 0x30;
            c2 += s[i] == 0x32, c3 += s[i] == 0x33;
        }
        int r = sum % 9;
        bool flag = false;
        if (r == 3 && c3 >= 1) flag = true;
        if (r == 6 && c3 >= 2) flag = true;
        if (c2 >= a[r]) flag = true;
        if (c3 >= 2 && c2 >= a[(r + 3) % 9]) flag = true;
        if (c3 >= 1 && c2 >= a[(r + 6) % 9]) flag = true;

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}