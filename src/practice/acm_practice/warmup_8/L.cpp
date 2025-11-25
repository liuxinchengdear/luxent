#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int sum = 0;
    for (int i = n; i ; i -- ) {
        int j = n - i;
        auto t = (i - 1) * n + j + 1;
        sum += t * 2 + 1;
    }
    cout << sum - n << '\n';
    return 0;
}