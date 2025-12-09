#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p10(10); p10[0] = 1;
    for (int i = 1; i < 10; ++ i) p10[i] = p10[i - 1] * 10; 

    int _T; cin >> _T; while (_T -- ) {
        int l, r; cin >> l >> r;
        int d = r - l, num = l;
        vector<int> a, b;
        while (l) a.push_back(l % 10), l /= 10;
        while (r) b.push_back(r % 10), r /= 10;

        vector<int> c; int sum = 0;
        for (int i = 0; num; ++ i) {
            int r = num % 10; int t = 0;
            while (sum + p10[i] * (t + 1) <= d && ((r + t) % 10 == a[i] || (r + t) % 10 == b[i])) ++ t;
            sum += t * p10[i]; num += t; r = num % 10;
            c.push_back(r);
            num /= 10;
        }

        int res = 0;
        for (int i = 0; i < a.size(); ++ i) res += (c[i] == a[i]) + (c[i] == b[i]);

        cout << res << endl;
    }

    return 0;
}