#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    auto binary_search = [&n](int a) -> int{
        int l = 1, r = sqrt(n / a) + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (1ll * mid * mid < n / a) l = mid + 1;
            else r = mid;
        }
        if (l * l > n / a) l -- ;
        return l;
    };

    int res = 0;
    for (int a = 2; a <= n; a *= 2) {
        auto t = binary_search(a);
        res += t + 1 >> 1;
    }
    cout << res << endl;
    return 0;
}