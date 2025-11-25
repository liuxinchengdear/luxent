#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c ,d;
    int op;
    int _T; cin >> _T; while (_T -- ) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> c;
            cout << ((a + c) / b) << endl;
        }
        else {
            cin >> a >> b >> d;
            cout << (d * b - a) << endl;
        }
    }
    return 0;
}