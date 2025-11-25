#include <bits/stdc++.h>
using namespace std;

#define int long long

using i128 = __int128;

string to_string(i128 x) {
    if (x == 0) return "0";
    string num;
    while (x > 0) {
        num = char(x % 10 + 0x30) + num;
        x /= 10;
    }
    return num;
}

ostream& operator << (ostream& cout, i128 x) {
    string num = to_string(x);
    cout << num;
    return cout;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    
    int num = 0;
    vector<int> a(n);
    for (auto &e : a) cin >> e, num = max(num, e);

    auto binary_search = [&](int x) -> int {
        int l = 0, r = 31; 
        while (l < r) {
            int mid = l + r >> 1;
            if (pow(2, mid) < x) l = mid + 1;
            else r = mid;
        }
        if (pow(2, l) > x) l -- ;
        return l;
    };

    int mx = binary_search(num);
    
    i128 res = -1;
    for (int opy = 0; opy <= mx; opy ++ ) {
        i128 tmp = 0;
        vector<int> ta = a;
        for (int i = 0; i < n; i ++ ) {
            int t = opy;
            while (t -- && ta[i]) {
                if (ta[i] & 1) tmp ++ ;
                ta[i] >>= 1;
            }
            tmp += ta[i];
        }
        tmp = tmp * x + opy * y;
        if (opy == 0) {res = tmp; continue;}
        res = min(res, tmp);
    }
    cout << res << '\n';
    return 0;
}