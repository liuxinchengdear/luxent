#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; while (t -- ) {
        // 只能使用一次
        vector<int> a(10);
        for (int i = 0; i < 10; i ++ ) cin >> a[i];
        int res = a[0] + a[4] + a[8];
        int odd = a[1] + a[3] + a[5] + a[7], even = a[2];
        auto mx = max(odd, even), mn = min(odd, even);
        auto num = a[6] + a[9];
        res += (mx - mn > num ? num + mn : mx + (num + mn - mx >> 1));
        cout << res << endl;
    }
    system("pause");
    return 0;
}