#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    auto check = [&](int x) -> bool {
        cout << "? " << x << endl;
        int num; cin >> num; 
        return num;
    };

    auto binary_search = [&](int l, int r) -> int {
        while (r - l > 1) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid;
        }
        return r - 1;
    };

    auto t = binary_search(1, n);
    cout << "! " << t << endl;
    return 0;
}