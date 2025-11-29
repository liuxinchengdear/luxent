#include <bits/stdc++.h>
using namespace  std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    int sum = n / 2 + n / 2 + (n % 2 ? 1 : 0) + ceil((n - n / 2) * 1.0 / 3);

    cout << sum << endl;
    return 0;
}