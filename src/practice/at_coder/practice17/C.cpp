#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> pw{0};

    for (int i = 1; i <= n / i; i ++ ) pw.push_back(i * i);

    int res = n;
    for (int i = 1; i < pw.size(); i ++ ) {
        int x = pw[i];
        auto p = lower_bound(pw.begin(), pw.end(), n - x);
        if (p == pw.begin()) res = min(res, abs(n - (x + *p)));
        else if (p == pw.end()) res = min(res, abs(n - (x + *prev(p))));
        else {
            res = min(res, min(abs(n - (x + *prev(p))), abs(n - (x + *p))));
        }
    }
    cout << res << endl;
    return 0;
}