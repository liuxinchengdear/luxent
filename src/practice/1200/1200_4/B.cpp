#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;

    int sum = 3 * a;
    if (a < b) {
        cout << "3\n" << (sum - (2 * b + 1)) << " " << b << " " << b + 1 << '\n';
    }
    else if (a == b) {
        cout << "1\n" << b <<  '\n';
    }
    else cout << "3\n" << b - 1 << " " << b << " " << (sum - (2 * b - 1)) << '\n';
    
    return 0;
}