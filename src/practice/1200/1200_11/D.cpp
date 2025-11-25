#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int cnt = count(a.begin() + 1, a.end(), 0);

        if (!cnt) {
            cout << n << '\n';
            for (int i = 1; i <= n; i ++ ) cout << i << " " << i << '\n';
        }
        else if (cnt == 1) cout << "-1\n";
        else {
            int st = 1, ed = n;
            vector<int> l(n + 1), r(n + 2);

            set<int> lt, rt;
            for (int i = 1; i <= n; i ++ ) {
                lt.insert(a[i]);
                for (int j = l[i - 1]; ; j ++ ) if (!lt.count(j)) {l[i] = j; break;}
            }

            for (int i = n; i; i -- ) {
                for (int j = r[i + 1]; ; j ++ ) if (!rt.count(j)) {r[i] = j; break;}
                rt.insert(a[i]);
            }

            bool flag = false;
            for (int i = 1; i < n; i ++ ) {
                if (l[i] == r[i]) {
                    flag = true; 
                    cout << "2\n";
                    cout << "1 " << i << '\n';
                    cout << i + 1 << " " << n << '\n';
                    break;
                }
            }
            if (!flag) cout << "-1\n";
        }
    }
    return 0;
}