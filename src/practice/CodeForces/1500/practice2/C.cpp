#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n; int op;

        cout << "digit" << endl; cin >> op;
        cout << "digit" << endl; cin >> op;
        cout << "add -8" << endl; cin >> op;
        cout << "add -4" << endl; cin >> op;
        cout << "add -2" << endl; cin >> op;
        cout << "add -1" << endl; cin >> op;
        cout << "mul " << n << endl; cin >> op;
        cout << "!" << endl; cin >> op;
    }
    return 0;
}