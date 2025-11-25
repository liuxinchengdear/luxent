#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, x; cin >> n >> m >> x;
        set<int> num; num.insert(x);
        for ( ; m -- ; ) {
            int dis; char op; cin >> dis >> op;
            if (op == '?') {
                int d1 = dis, d2 = n - dis;
                set<int> tmp;
                for (auto e : num) {
                    tmp.insert((e + d1 - 1) % n + 1);
                    tmp.insert((e + d2 - 1) % n + 1);
                }
                num = tmp;
            }
            else {
                set<int> tmp;
                for (auto e : num) {
                    int t = op == 0x30 ? (dis + e - 1) % n + 1 : (n - dis + e - 1) % n + 1;
                    tmp.insert(t);
                }
                num = tmp;
            }
        }

        cout << num.size() << '\n';
        for (auto e : num) cout << e << " "; cout << '\n';
    }
    return 0;
}