#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        auto query = [](int l, int r) -> bool {
            int pm, am;
            cout << "1 " << l << " " << r << endl;
            cin >> pm;
            cout << "2 " << l << " " << r << endl;
            cin >> am;
            return pm == am;
        };

        auto binary_search = [&](int l, int r, int op) -> int {
            if (op == 1) {
                while (l < r) {
                    int mid = l + r >> 1;
                    if (query(1, mid)) l = mid + 1;
                    else r = mid;
                }
                return r;
            }
            else {
                while (l < r) {
                    int mid = l + r >> 1;
                    if (query(mid, n)) r = mid;
                    else l = mid + 1;
                }
                return r - 1;
            }
        };

        int l = binary_search(1, n, 1);

        int p, a;
        cout << "1 " << l << " " << n << endl;
        cin >> p;
        cout << "2 " << l << " " << n << endl;
        cin >> a;

        int r = l + a - p - 1;

        cout << "! " << l << " " << r << endl;
    }
    return 0;
}